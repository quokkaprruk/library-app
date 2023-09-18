/* Citation and Sources...
Final Project Milestone ?
Module: Menu
Filename: LibApp.cpp
Version 2.0
Author	Siripa Purinruk
Revision History
-----------------------------------------------------------
Date      Reason
2023/August/6
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Utils.h"
#include "LibApp.h"
#include "PublicationSelector.h"
#include <fstream>

using namespace std;
namespace sdds {

	//public: Constructor
	LibApp::LibApp(const char* filename):
		m_mainMenu("Seneca Library Application"), 
		m_exitMenu("Changes have been made to the data, what would you like to do?"),
		m_pubType("Choose the type of publication:"),
		m_changed(false)
		 {
		
		if (filename) {
			strcpy(a_fname, filename);
		}
	
		m_changed = false;
		

		//populates mainMenu item
		m_mainMenu << "Add New Publication" 
			<< "Remove Publication"
			<< "Checkout publication from library" 
			<< "Return publication to library";

		//populates exitMenu item
		m_exitMenu << "Save changes and exit" 
			<< "Cancel and go back to the main menu";

		//MS5 add m_pubType menu
		//Setup the publication type menu in the constructor 
		m_pubType << "Book" << "Publication";
		a_NOLP = 0;

		load();
		
	};

	LibApp::~LibApp()
	{
		for (int i = 0; i < a_NOLP; i++) {
			delete a_PPA[i];
		}
	}

	//private method:
	bool LibApp::confirm(const char* message) {

		Menu menu(message);
		menu << "Yes";
		return menu.run() == 1;
	};

	
	void LibApp::load() {
		
		cout << "Loading Data\n";
		ifstream file(a_fname); 

		char type = {};
		
		//Continue this until the ifstream reading fails.no more char to read
		for (int i = 0; file && i < SDDS_LIBRARY_CAPACITY; i++) {
			
			file >> type; // cin >> type // #include <fstream>
			file.ignore();
			if (file) { // the read operation is successful 

				if (type == 'B') a_PPA[i] = new Book;
				else if (type == 'P') a_PPA[i] = new Publication;

				if (a_PPA[i]) {
					/*Then extract the object from the file stream */
					file >> *a_PPA[i];

					//add one to the NOLP 
					a_NOLP++;

					//set the reference number of the last publication read.
					a_LLRN = a_PPA[i]->getRef();
				}
			}
			
		}

		file.close();
		
	};

	// prints: "Saving Data"<NEWLINE>
	void LibApp::save() {

		cout << "Saving Data\n";
		ofstream file(a_fname);

		for (int i = 0; i < a_NOLP; i++) {
			if (a_PPA[i]->getRef() != 0) {

				file << *a_PPA[i] << endl; //**newline //for ms1
			}
		
		}

		file.close();
	};

	// prints: "Searching for publication"<NEWLINE>
	int LibApp::search(int searchFor) {
		
		/*searchFor
		1. all
		2. only those pb which are on loan
		3. only those pb which are not on loan
		*/

		//invoke constructor
		PublicationSelector pub("Select one of the following found matches:", 15);
		//get the type of publication to search for from the user
		char temp_type = {};
		unsigned pubType = m_pubType.run(); //show the menu 1. book , 2. publication
		
		if (pubType == 1) {
			temp_type = 'B';
		}
		else if (pubType == 2) {
			temp_type = 'P';
		}
		cin.ignore(100, '\n');

		//print title and get the title to search the PPA
		cout << "Publication Title: ";

		char temp_title[SDDS_TEMPTITLE]{};
		cin.getline(temp_title, SDDS_TEMPTITLE);

		//show what the user is looking for
		if (searchFor == 1) { //1. all
			
			for (int i = 0; i < a_NOLP; i++) {
				if (a_PPA[i]->operator==(temp_title) && temp_type == a_PPA[i]->type() && a_PPA[i]->getRef() != 0) {

					pub << a_PPA[i];
				}
			}
		}
		else if (searchFor == 2) { // 2.
			
			for (int i = 0; i < a_NOLP; i++) {
				if (a_PPA[i]->operator==(temp_title) && a_PPA[i]->onLoan() && temp_type == a_PPA[i]->type() && a_PPA[i]->getRef() != 0) {
					pub << a_PPA[i];
				}
			}
		}
		else if (searchFor == 3) { //3.
			
			for (int i = 0; i < a_NOLP; i++) {
				if (a_PPA[i]->operator==(temp_title) && !a_PPA[i]->onLoan() && temp_type == a_PPA[i]->type() && a_PPA[i]->getRef() != 0) {
					pub << a_PPA[i];
				}
			}

		}

		//If matches are found, sort the result and get the user's selection 
		//and return the library reference number. If not print "No matches found!"
		int libRef = 0; //pubSelector
		if (pub) {
	
			pub.sort();
			libRef = pub.run();

			if (libRef > 0) {
				cout << *getPub(libRef) << endl;
			}
			else {
				cout << "Aborted!" << endl;
			}
		}
		else {
			cout << "No matches found!" << endl;
		}
		
		return libRef;

	};

	void LibApp::returnPub() {
		
		cout << "Return publication to the library\n";

		int libRef =search(2);//search which are on loan
		if (libRef > 0) {

			if (confirm("Return Publication?")) {
				//calculate penalty
				int daysOnLoan = Date() - getPub(libRef)->checkoutDate();

				if (daysOnLoan > SDDS_MAX_LOAN_DAYS) {
					double charged = (daysOnLoan - SDDS_MAX_LOAN_DAYS) * 0.5;
					printf("Please pay $%.2lf penalty for being %d days late!\n", charged, daysOnLoan - SDDS_MAX_LOAN_DAYS);

				}

				//set the membership number of the publication to 0 (zero)
				getPub(libRef)->set(0);
				m_changed = true;
				
			}
			cout << "Publication returned\n" << endl;
		}
		cout << "\n";
		
	};

	void LibApp::newPublication() {

		bool exit = false;

		//unsigned pubType;
		if(a_NOLP == SDDS_LIBRARY_CAPACITY)
		{
			cout << "Library is at its maximum capacity!" <<endl;
			exit = true;
		}

		if(!exit) { //exit == false
			cout << "Adding new publication to the library" << endl;
			
			//get publication type from the user.
			int pubType = m_pubType.run();
			cin.ignore(100, '\n');
			
			// Instantiating a dynamic publication(create obj)
			Publication* pp = nullptr;
			if (pubType == 1) {
				
				pp = new Book();
				//Read the instantiated object from the cin object...
				if (pp) {
					cin >> *pp;
				}
			}
			else if (pubType == 2) {
				pp = new Publication();
				if (pp) {

					cin >> *pp;
				}
			}
			else if (pubType == 0) {
				
				cout << "Aborted!" << endl;
				exit = true;

			}

			if (cin.fail()) {
				//flush the keyboard: ignore and clear
				cin.ignore(100, '\n');
				cin.clear();
				cout << "Aborted!" << endl;
				exit = true;
			}
			else {
				if (!exit && confirm("Add this publication to the library?")) {
					if (*pp) { //due to the warning of dereferencing

						a_LLRN++;
						pp->setRef(a_LLRN);

						a_PPA[a_NOLP] = pp;
						a_NOLP++;
						m_changed = true;

						cout << "Publication added" << endl;
						
					}
					else
					{
						cout << "Failed to add publication!" << endl;
						//delete the allocated memory
						delete pp;
					}
					
				}
			}
		}
		cout << endl;
	};

	void LibApp::removePublication() {
		cout << "Removing publication from the library" << endl;
		int libRef = search(1); //search all pub
		if (libRef > 0) {

			if (confirm("Remove this publication from the library?")) {
				getPub(libRef)->setRef(0);
				m_changed = true;
				cout << "Publication removed" << endl;
			}
		}
		cout << endl;
	};
	
	void LibApp::checkOutPub() {
		cout << "Checkout publication from the library\n";
		int libRef = search(3); // Search only not on loan
	
		if (libRef > 0) {

			if (confirm("Check out publication?")) {
				cout << "Enter Membership number: ";
				bool valid = false;
				int membership;
				while (!valid) {
					cin >> membership;
					if (!cin || membership < 10000 || membership > 99999) {
						cout << "Invalid membership number, try again: ";
						cin.clear();
						cin.ignore(1000, '\n');
						valid = false;
					}
					else {
						valid = true;
					}
				}

				getPub(libRef)->set(membership);
				m_changed = true;
				cout << "Publication checked out" << endl;
				
			}
		}
		cout << endl;
	};
	



	//ms5 added
	Publication* LibApp::getPub(int libRef) {
		
		Publication* p = nullptr;

		for (int i = 0; i < a_NOLP; i++) {
			if (a_PPA[i]->getRef() == libRef) {
				p = a_PPA[i];
			}
		}
		return p;
	};

	//ms5 added
	std::ostream& LibApp::run(std::ostream& os) {
		unsigned selectMainmenu, selectExitmenu;
		
		do {

			selectMainmenu = m_mainMenu.run();//will disply title, menu, check validInt

			switch (selectMainmenu) {
			case 1: newPublication();
				break;
			case 2: removePublication();
				break;
			case 3: checkOutPub();
				break;
			case 4: returnPub();
				break;
			default:
				if (m_changed == true) {

					selectExitmenu = m_exitMenu.run();

					switch (selectExitmenu) {
					case 0:
						if (confirm("This will discard all the changes are you sure?")) {
							m_changed = false;
						}
						break;	
					case 1: 
						save();
						break;
					case 2: //discard selected(goback to main menu)
						//before going to main => confirm first
						selectMainmenu = 1;
						break;
						      
					}
				}
				cout << endl;
				
			}
		} while (selectMainmenu != 0);
		
		cout << "-------------------------------------------\n"
				"Thanks for using Seneca Library Application\n";
		return os;
	};



}

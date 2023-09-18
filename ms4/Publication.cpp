// Final Project Milestone 3
// Periodical Publication 
// Author	Fardad Soleimanloo
// Revision History
// -----------------------------------------------------------
// Name Siripa Purinruk              Date  22/July/2023               Reason
/////////////////////////////////////////////////////////////////
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Publication.h"
#include "Utils.h"
#include "Lib.h"
#include <iomanip>

using namespace std;
namespace sdds {


	void Publication::setDefault() {
		m_title = nullptr;
		m_shelfId[0] = '\0';
		m_membership = 0;
		m_libRef = -1;
		resetDate();
	}

	Publication::Publication() {
		setDefault();//easier
	}
		
	Publication::Publication(const Publication& src) {
		if (this != &src) {
			*this = src;
		}
		
	};
	Publication& Publication::operator=(const Publication& src) {
		if (this != &src) {
			
			set(src.m_membership);
			setRef(src.m_libRef);
			strCpy(m_shelfId, src.m_shelfId); //exactly 5 number
			m_date = src.m_date;

			if (m_title != nullptr) {
				delete[] m_title;
				m_title = nullptr;
			}
			//copy
			if (src.m_title != nullptr) {
				m_title = new char[strLen(src.m_title) + 1];
				//copy
				strCpy(m_title, src.m_title);
				
			}
			else {
				m_title = nullptr;
			}	

		}
		return *this;
	};
	Publication::~Publication() {
		delete[] m_title;
		m_title = nullptr;
	};

	//modifiers
	void Publication::set(int member_id) {
		m_membership = member_id;
	};
	void Publication::setRef(int value) {
		m_libRef = value;
	};
	void Publication::resetDate() {
		m_date = Date();
	};

	//queries
	char Publication::type()const {
		char ch = 'P'; //publication obj
		return ch;
	};

	bool Publication::onLoan()const {
		return (m_membership != 0);
	};

	Date Publication::checkoutDate()const {
		return m_date;
	};

	bool Publication::operator==(const char* title)const {
		
		return  strstr(m_title, title) != nullptr;
	};

	Publication::operator const char* ()const {
		return m_title;
	};

	int Publication::getRef()const {
		return m_libRef;
	};

	//Streamable pure virtual function implementations
	std::ostream& Publication::write(std::ostream& os) const {
		char title[SDDS_TITLE_WIDTH + 1] = { 0 };
		strncpy(title, m_title, SDDS_TITLE_WIDTH);

		if (conIO(os)) {
			
			os << "| " << left << setw(5) << setfill(' ') << m_shelfId;
			os << "| " << left << setw(30) << setfill('.') << title << " | ";
			(m_membership != 0) ? os << m_membership : os << " N/A ";
			os << " | " << m_date << " |";// << endl;
		}
		else {
			os << type() << "\t\t"; //print 'P'
			os << m_libRef << "\t" << m_shelfId << "\t" << m_title << "\t";
			(m_membership != 0) ? os << m_membership : os << " N/A ";
			os << "\t" << m_date;
				
		}
		//os << endl;
		return os;
	};

	std::istream& Publication::read(std::istream& istr) {
		//temp variable
		char temp_title[SDDS_M_TITLE_LEN + 1] = { '\0' }; 
		char temp_shelfId[SDDS_SHELF_ID_LEN + 1] = { '\0' };
		int temp_membership = 0; 
		int temp_libRef = -1;
		Date temp_date;

		//clear all the attributes by freeing the memory and setting 
		//everything to their default values.
		if (m_title != nullptr) {
			delete[] m_title;
			m_title = nullptr;
		}
		setDefault();

		if (conIO(istr)) {
			cout << "Shelf No: ";
			istr.getline(temp_shelfId, (SDDS_SHELF_ID_LEN) + 1);
			if (strLen(temp_shelfId) != SDDS_SHELF_ID_LEN) {
				istr.setstate(std::ios::failbit);//??
			}
			std::cout << "Title: ";
			istr.getline(temp_title, SDDS_M_TITLE_LEN +1);
			std::cout << "Date: ";
			istr >> temp_date;
		}
		else {
			istr >> temp_libRef; //int
			istr.ignore();
			istr.getline(temp_shelfId, SDDS_SHELF_ID_LEN +1, '\t'); //char
			istr.getline(temp_title, SDDS_M_TITLE_LEN, '\t'); //getline is used for char[] not char*
			istr >> temp_membership; // int
			istr.ignore();
			istr >> temp_date; //int

		}
		//
		if (!temp_date) { //if date is invalid
			istr.setstate(std::ios::failbit);// set on an input stream to indicate that a failure has occurred during input operations
		}
		
		if (!istr.fail()) {
		
			m_title = new char[strlen(temp_title) + 1];
			strCpy(m_title, temp_title);
			strCpy(m_shelfId, temp_shelfId);
			m_membership = temp_membership;
			m_date = temp_date;
			m_libRef = temp_libRef;
		}
		return istr;
	};

	
	bool Publication::conIO(std::ios& iosObj)const {
		
		return ( &iosObj == &cin || &iosObj == &cout);
	};

	Publication::operator bool()const {
	
		return (m_title != nullptr && m_title[0] != '\0') && m_shelfId[0] != '\0';
	};

}
#ifndef SDDS_LIBAPP_H
#define SDDS_LIBAPP_H
#include "Menu.h"
#include "Lib.h"
#include "Publication.h"
#include "Book.h"
namespace sdds {
	class LibApp {
		/*const int SDDS_FNAME = 256;*/

		//ms5 added

		Menu m_mainMenu ;
		Menu m_exitMenu ;
		Menu m_pubType;
		bool m_changed ;

		char a_fname[SDDS_FNAME+1];
		Publication* a_PPA[SDDS_LIBRARY_CAPACITY]; //populated with all the records of the publication data file
		int a_NOLP;//hold the number of Publications loaded into the PPA.
		int a_LLRN;//hold the last library reference number
		
		//method:
		bool confirm(const char* message);
		void load();  // prints: "Loading Data"<NEWLINE>
		void save();  // prints: "Saving Data"<NEWLINE>
		int search(int searchFor);  // prints: "Searching for publication"<NEWLINE>

		void returnPub();  /*  Calls the search() method.
							   prints "Returning publication"<NEWLINE>
							   prints "Publication returned"<NEWLINE>
							   sets m_changed to true;
						   */
		void newPublication();
		void removePublication();
		void checkOutPub();
	public:
		LibApp(const char* filename);
		std::ostream& run(std::ostream& os = std::cout);
		~LibApp();
		//ms5 added
		Publication* getPub(int libRef);
	};
}
#endif // !SDDS_LIBAPP_H




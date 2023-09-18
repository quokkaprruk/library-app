#ifndef SDDS_LIBAPP_H
#define SDDS_LIBAPP_H
#include "Menu.h"

namespace sdds {
	class LibApp {
		Menu m_mainMenu ;
		Menu m_exitMenu ;
		bool m_changed ;
		//LibApp is  friend of Menu
		
		//method:
		bool confirm(const char* message);
		void load();  // prints: "Loading Data"<NEWLINE>
		void save();  // prints: "Saving Data"<NEWLINE>
		void search();  // prints: "Searching for publication"<NEWLINE>

		void returnPub();  /*  Calls the search() method.
							   prints "Returning publication"<NEWLINE>
							   prints "Publication returned"<NEWLINE>
							   sets m_changed to true;
						   */
		void newPublication();
		void removePublication();
		void checkOutPub();
	public:
		LibApp();
		std::ostream& run(std::ostream& os = std::cout);
		
	};
}
#endif // !SDDS_LIBAPP_H




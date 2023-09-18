#ifndef SDDS_MENU_H
#define SDDS_MENU_H

namespace sdds {
	const unsigned int MAX_MENU_ITEMS = 20;

	class MenuItem { //holds only one Cstring of characters for the content of the menu item dynamically.
		
	private:
		char* m_content{ nullptr };

		//Make the “Menu” class a friend of this class**
		friend class Menu;

		MenuItem();
		MenuItem(const char* newcontent);
		~MenuItem();
		//no copy
		MenuItem(const MenuItem& src) = delete; //create new obj
		MenuItem& operator=(const MenuItem& src) = delete; //assign content of one obj to another

		//set to empty state
		void setEmpty();
		operator bool() const;
		operator const char* ()const;
		std::ostream& displayContent(std::ostream& os = std::cout);//no const
	};

	class Menu {
		MenuItem m_title{ nullptr };//char* m_title{ nullptr }; ???
		MenuItem* m_items[MAX_MENU_ITEMS]{ nullptr }; //direct initialization: automatically initializes all the elements of the array to nullptr. So, dont need for loop in costr
		unsigned menuItemCount = 0;

		
	public:
		Menu();
		Menu(const char* newtitle);
		~Menu();
		Menu(const Menu& menu) = delete;
		Menu& operator=(const Menu& menu) = delete;

		//function display title of title
		std::ostream& displayTitle(std::ostream& os);//no const
		//function display menuItems
		std::ostream& displayEntireMenu(std::ostream& os = std::cout);//no const

		unsigned int run();

		unsigned int operator~();

		//from prof.
		Menu& operator<<(const char* menuitemContent);

		operator int() const;
		operator unsigned int() const;
		operator bool() const;

		//overload the indexing operator
		const char* operator[] (int index) const;
	};

	std::ostream& operator << (std::ostream& os, Menu& menu);
}
#endif // !1

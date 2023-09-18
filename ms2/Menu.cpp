/* Citation and Sources...
Final Project Milestone 2
Module: Menu
Filename: Menu.cpp
Version 1.0
Author	Siripa Purinruk
Revision History
-----------------------------------------------------------
Date      Reason
2023/July/10
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS
#include <iomanip>
#include <iostream>

using namespace std;
#include "Menu.h"
#include "Utils.h"

namespace sdds {


	void MenuItem::setEmpty() {
		delete[] m_content;
		m_content = nullptr;
	};

	MenuItem::MenuItem() {
		//if no value provided, set to empty state
		setEmpty();
	};

	MenuItem::MenuItem(const char* newcontent) {

		if (newcontent != nullptr && newcontent[0] != '\0') {
			m_content = new char[strLen(newcontent) + 1];
			strCpy(m_content, newcontent);
		}
		else {
			setEmpty();
		}
	};

	MenuItem::~MenuItem() {
		delete[] m_content;
		m_content = nullptr;
	};

	MenuItem::operator bool() const {
		//return true if it's not empty
		return m_content != nullptr && m_content[0] != '\0';
	};
	MenuItem::operator const char* ()const {
		return m_content;
	};
	std::ostream& MenuItem::displayContent(std::ostream& os) {

		if (*this) { os << m_content; }
		return os;
	};


	Menu::Menu() {
		menuItemCount = 0;
	};

	Menu::Menu(const char* newtitle) : m_title(newtitle) {};


	Menu::~Menu() {
		for (unsigned i = 0; i < MAX_MENU_ITEMS; i++) {
			delete m_items[i];
			m_items[i] = nullptr;
		}
	};

	//display title of Menu
	std::ostream& Menu::displayTitle(std::ostream& os) {
		if (m_title != nullptr && m_title[0] != '\0') {
			m_title.displayContent();
		}
		return os;
	};

	//display menuItems
	std::ostream& Menu::displayEntireMenu(std::ostream& os) {
		if (m_title != nullptr && m_title[0] != '\0') {
			m_title.displayContent();
			os << "\n";
		}

		for (unsigned i = 0; i < menuItemCount; i++) {
			os << right << setw(2) << setfill(' ') << i + 1 << "- ";
			m_items[i]->displayContent(os);
			os << endl;
		}
		os << " 0- Exit\n" << "> ";
		return os;

	};

	unsigned int Menu::run() {
		displayEntireMenu();
		unsigned int selectMenu = getValidInteger(0, menuItemCount);

		return selectMenu;
	};

	unsigned int Menu::operator~() {
		return run();
	};

	Menu& Menu::operator<<(const char* menuitemContent) {
		
		if (menuItemCount < MAX_MENU_ITEMS) {
		
			m_items[menuItemCount] = new MenuItem(menuitemContent); //add new item from MenuItem to m_items

			menuItemCount++;
		}
		return *this; //return to Menu Obj.
	};

	Menu::operator int() const {
		return menuItemCount;
	};

	Menu::operator unsigned int() const {
		return menuItemCount;
	};

	Menu::operator bool() const {
		return menuItemCount > 0;
	};

	const char* Menu::operator[] (int index) const {
		
		const char* result = nullptr;
		int element = 0;

		if (*this) { 
			element = index % menuItemCount;
			result = m_items[element]->m_content;
		}

		return result;
	};

	//standalone function
	std::ostream& operator<< (std::ostream& os, Menu& menu) {
		menu.displayTitle(os);
		return os;
	};

}




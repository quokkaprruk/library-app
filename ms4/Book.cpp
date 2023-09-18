#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Book.h"
#include <iomanip>
#include <cstring>
using namespace std;

namespace sdds {
	
//public:
	void Book::setDefault() {
		b_author = nullptr;
	};
	Book::Book():Publication() {
		setDefault();
	};

	Book::Book(const Book & src):Publication(src) { 
		if (this != &src) {
			if (b_author != nullptr) {
				delete[] b_author;
				b_author = nullptr;
			}
			b_author = new char[strlen(src.b_author) + 1];
			strcpy(b_author, src.b_author);
		}
	};

	Book& Book::operator=(const Book& src) { 
		if (this != &src) {
			Publication::operator=(src);
			if (b_author != nullptr) {
				delete[] b_author;
				b_author = nullptr;
			}

			if (src.b_author != nullptr) {
				b_author = new char[strlen(src.b_author) + 1];
				strcpy(b_author, src.b_author);

				
			}
		}
		return *this;
	};
	Book::~Book() {
		delete[] b_author;
		b_author = nullptr;
	};

	//override :1.type, 2.write, 3.read, 4.set, 5.operator bool()
	char Book::type()const {
		return 'B';
	};
	std::ostream& Book::write(std::ostream& os) const {
		Publication::write(os);
		if (conIO(os)) {
			char temp_author[SDDS_AUTHOR_WIDTH + 1] = { 0 };
			strncpy(temp_author, b_author, SDDS_AUTHOR_WIDTH);
			os << " ";
			os << left << setw(SDDS_AUTHOR_WIDTH) << setfill(' ') << temp_author << " |";

		}
		else {
			os << "\t" << b_author;
		}
		return os;
	
	};
	std::istream& Book::read(std::istream& istr) {
		Publication::read(istr);
		if (b_author != nullptr) {
			delete[] b_author;
			b_author = nullptr;
		}

		char temp_authorName[201] = {};
		if (conIO(istr)) {
			istr.ignore();
			cout << "Author: ";
		
		}
		else {
			istr.ignore(1000, '\t');
		}

		istr.get(temp_authorName, 201);
		if (istr) {
			b_author = new char[strlen(temp_authorName) + 1];
			strcpy(b_author, temp_authorName);
		}
		return istr;
	};
	void Book::set(int member_id) {
		Publication::set(member_id);
		Publication::resetDate();
	};
	Book::operator bool()const {
		return (b_author != nullptr && b_author[0] != '\0') && Publication::operator bool();
	};


	
}
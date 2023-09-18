/***********************************************************************
// OOP244 Utils Module
// File	Utils.cpp
// Version
// Date
// Author
// Description
//
// Revision History
// -----------------------------------------------------------
// Name  Siripa Purinruk             Date   15/7/2023      Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/
/*
I have done all the coding by myselfand only copied the code
that my professor provided to complete my workshopsand assignments.
*/
#include <iostream>
#include "Utils.h"

using namespace std;


namespace sdds {

	unsigned int getValidInteger(unsigned int min, unsigned int max) {

		unsigned value;
		bool result = false;

		do {
			cin >> value;
			if (!cin || value < min || value > max) {
				cout << "Invalid Selection, try again: ";
				cin.clear();
				cin.ignore(1000, '\n');
				result = false;
			}
			else {
				result = true;
			}

		} while (result == false);
		return value;
	};

	int strLen(const char* s) {
		int length = 0;
		while (s[length] != '\0') {
			length++;
		}
		return length;
	}

	void strCpy(char* des, const char* src) {
		int i = 0;
		while (src[i] != '\0') {
			des[i] = src[i];
			i++;
		}
		des[i] = '\0';
	}

	void strnCpy(char* des, const char* src, int len) {

		int i = 0;

		//loop if meet src[i] != '\0' and i < len
		while (i < len && src[i] != '\0') {
			des[i] = src[i];
			i++;
		}

		//if the number of the characters copied is less than "len"
		if (i < len) {
		
			des[i] = '\0';
		}

	};

	int strCmp(const char* s1, const char* s2) {

		int i = 0;

		//loop when s1[i] and s2[i] don't meet '\0' and char s1[i] == s2[i]
		while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i]) {
			i++;//check each character
		}

		return s1[i] - s2[i];

	};

	int strnCmp(const char* s1, const char* s2, int len) {

		int i = 0;
		while (i < len && s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i]) {
			i++;//check each character
		}

		return (i == len) ? 0 : (s1[i] - s2[i]);

	};

	void strCat(char* des, const char* src) {

		int lenDes = 0, lenSrc = 0;

		while (des[lenDes] != '\0') {
			lenDes++;
		}


		while (src[lenSrc] != '\0') {
			des[lenDes] = src[lenSrc];

			lenSrc++;
			lenDes++;
		}
		des[lenDes] = '\0';
	};

	const char* strStr(const char* str1, const char* str2) {
		if (str1 == nullptr || str2 == nullptr) {
			return nullptr;
		}

		if (*str2 == '\0') {
			return str1;
		}

		const char* p1 = str1;
		while (*p1) {
			const char* p1Current = p1;
			const char* p2 = str2;

			while (*p1Current && *p2 && *p1Current == *p2) {
				p1Current++;
				p2++;
			}

			if (*p2 == '\0') {
				return p1;
			}

			p1++;
		}

		return nullptr;
	}


}
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

#include <iostream>
#include "Utils.h"
#include "Menu.h"

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
		return value;//mistake: put outside of the loop!
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

		while (i < len && src[i] != '\0') {
			des[i] = src[i];
			i++;
		}

		if (i < len) {
			des[i] = '\0';
		}

	};

	int strCmp(const char* s1, const char* s2) {

		int i = 0;

		while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i]) {
			i++;
		}

		return s1[i] - s2[i];

	};

	int strnCmp(const char* s1, const char* s2, int len) {

		int i = 0;
		while (i < len && s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i]) {
			i++;
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
		int i, j;
		int len1 = 0, len2 = 0;

		while (str1[len1] != '\0') {
			len1++; // get length of str1
		}

		while (str2[len2] != '\0') {
			len2++; // get length of str2
		}

		for (i = 0; i < len1; i++) {
			int flag = 1;
			for (j = 0; j < len2 && flag; j++) {
				if (i + j >= len1 || str1[i + j] != str2[j]) {
					flag = 0;
				}
			}

			if (flag && j == len2) {
				return &str1[i];
			}
		}
		return nullptr;
	}

}
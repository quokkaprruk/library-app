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
			//assign src[i] to des[i]
			des[i] = src[i];
			i++;
		}

		//if the number of the characters copied is less than "len"
		if (i < len) {
			//des will be null terminated
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
		//loop when s1[i] and s2[i] don't meet '\0' and char s1[i] == s2[i] and the number of character < len
		while (i < len && s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i]) {
			i++;//check each character
		}

		//after get out of the loop, if check (i == len) is true => it means both s1 and s2 are matched 
		return (i == len) ? 0 : (s1[i] - s2[i]);

	};

	void strCat(char* des, const char* src) {

		int lenDes = 0, lenSrc = 0;

		//get the len of des
		while (des[lenDes] != '\0') {
			lenDes++;
		}


		while (src[lenSrc] != '\0') {
			//assign src[lenSrc] to the end of des[lenDes]
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

		// loop until reach len1 of str1
		for (i = 0; i < len1; i++) {
			int flag = 1;
			// loop until reach len2 of str2
			for (j = 0; j < len2 && flag; j++) {
				if (i + j >= len1 || str1[i + j] != str2[j]) {
					flag = 0;
				}
			}

			// when out of the second for-loop, j==len2 means both str matched 
			if (flag && j == len2) {
				return &str1[i];
			}
		}
		return nullptr;
	}

}
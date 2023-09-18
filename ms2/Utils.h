/***********************************************************************
// OOP244 Utils Module
// File	Utils.h
// Version 2.0
// Date 10 July 2023
// Author
// Description
//
// Revision History
// -----------------------------------------------------------
// Name   Siripa Purinruk         Date  10 July 2023          Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/
#ifndef SDDS_UTILS_H__
#define SDDS_UTILS_H__

namespace sdds {
	unsigned int getValidInteger(unsigned int min, unsigned int max);
	int strLen(const char* s);
	void strCpy(char* des, const char* src);
	void strnCpy(char* des, const char* src, int len);
	int strCmp(const char* s1, const char* s2);
	int strnCmp(const char* s1, const char* s2, int len);
	void strCat(char* des, const char* src);
	const char* strStr(const char* str1, const char* str2);
}
#endif // SDDS_UTILS_H__

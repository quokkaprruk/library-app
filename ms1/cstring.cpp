//#include <iostream>
#include "cstring.h"

using namespace std;

namespace sdds {

    // Copies the source character string into the destination 
    void strCpy(char* des, const char* src) {
    
        int i = 0;

        //loop until meet src[i] == '\0'
        while (src[i] != '\0') {

            //assign src[i] to des[i]
            des[i] = src[i];
            i++;
        }
        //add '\0' at the end of the string
        des[i] = '\0';
    
    };
    // Copies the source character string into the destination upto "len"
    // characters. The destination will be null terminated only if the number of the characters copied is less than "len"
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
    // Compares two C-strings 
    // returns 0 i thare the same
    // return > 0 if s1 > s2
    // return < 0 if s1 < s2
    int strCmp(const char* s1, const char* s2) {
    
        int i = 0;
        

        //loop when s1[i] and s2[i] don't meet '\0' and char s1[i] == s2[i]
        while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i]) {
            i++;//check each character
        }

        return s1[i] - s2[i];
    
    };

    // returns 0 i thare the same
    // return > 0 if s1 > s2
    // return < 0 if s1 < s2
    int strnCmp(const char* s1, const char* s2, int len) {

        int i = 0;
        //loop when s1[i] and s2[i] don't meet '\0' and char s1[i] == s2[i] and the number of character < len
        while (i < len && s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i]) {
            i++;//check each character
        }

        //after get out of the loop, if check (i == len) is true => it means both s1 and s2 are matched 
        return (i == len) ? 0 : (s1[i] - s2[i]);
    
    };
    // returns the lenght of the C-string in characters
    int strLen(const char* s) {
        int len = 0;

        while (s[len] != '\0') {

            //count the len
            len++;
        }
        return len;
    };
    // returns the address of first occurance of "str2" in "str1"
    // returns nullptr if no match is found
    /*char str1[80] = "abcdefghijklmnopqrstuvwxyz";
     fadd = strStr(str1, "jkl");*/
    const char* strStr(const char* str1, const char* str2) {

            int i, j;
            int len1 = 0, len2 = 0;

            while (str1[len1] != '\0') {
                len1++; // get len1 of str1
            }

            while (str2[len2] != '\0') {
                len2++; // get len2 of str2
            }

            //loop until reach len1 of str1
            for (i = 0; i < len1; i++) {
                int flag = 1;
                //loop until reach len2 of str2
                for (j = 0; j < len2 && flag; j++) {
                    if (str1[i + j] != str2[j]) {
                        flag = 0;
                    }
                }

                //when get out of the second for-loop, j==len2 means both str matched 
                if (flag && j == len2) {
                    return &str1[i];
                }
            }
            return nullptr;
        
    };

    // Concantinates "src" C-string to the end of "des"
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

};
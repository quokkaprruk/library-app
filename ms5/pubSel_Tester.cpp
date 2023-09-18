// Final Project 
// PublicationSelector Usage demonstration
// File	pubSel_Tester.cpp
// Version 1.0
// Author	Fardad Soleimanloo
// Revision History
// -----------------------------------------------------------
// Name  Siripa Purinruk             Date                 Reason
//                    
/////////////////////////////////////////////////////////////////
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <cstring>
#include "Publication.h"
#include "Book.h"
#include "PublicationSelector.h"

using namespace std;
using namespace sdds;

void prnPub(Publication* p[], int size, int ref) {
   int i;
   for (i = 0; i < size; i++) {
      if (ref == p[i]->getRef()) {
         cout << *p[i] << endl;
         i = size; // Exit the loop.
      }
   }
}

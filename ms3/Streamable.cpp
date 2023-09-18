// Final Project Milestone 3
// Periodical Publication 
// Author	Fardad Soleimanloo
// Revision History
// -----------------------------------------------------------
// Name Siripa Purinruk              Date  20/July/2023               Reason
/////////////////////////////////////////////////////////////////
#include <iostream>
#include "Streamable.h"

namespace sdds {

	Streamable::~Streamable() {};

	std::ostream& operator<< (std::ostream& os, const Streamable& stream) {
		//can be written only when the object is valid****
		//if dont have this condition => error
		if (stream) {
			stream.write(os);
		}
		return os;
	};

	std::istream& operator>> (std::istream& is, Streamable& stream) {
		stream.read(is);
		return is;
	};
}
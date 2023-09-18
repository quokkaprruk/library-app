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

	//virtual
	Streamable::~Streamable() {}; //doesn't perform any deallocation

	std::ostream& operator<< (std::ostream& os, const Streamable& stream) {
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
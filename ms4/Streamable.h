#ifndef SDDS_STREAMABLE_H
#define SDDS_STREAMBLE_H
#include <iostream>
namespace sdds {
	class Streamable { 
		//becomes abstract class
		//This is an interface(no data member)
	public:
		//pure vitual
		virtual std::ostream& write(std::ostream& os) const = 0;

		virtual std::istream& read(std::istream& istr) = 0;

		virtual bool conIO(std::ios& iosObj)const = 0;

		virtual operator bool()const = 0;

		virtual ~Streamable();
	};

	std::ostream& operator<< (std::ostream& os, const Streamable& stream);
	std::istream& operator>> (std::istream& is, Streamable& stream);


}
#endif // !SDDS_STREAMABLE_H

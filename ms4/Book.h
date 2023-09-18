#ifndef SDDS_BOOK_H
#define SDDS_BOOK_H
#include "Publication.h"
namespace sdds {
	class Book:public Publication {

		char* b_author;

	public:
		Book();
		Book (const Book& src); 
		Book& operator=(const Book& src);
		~Book();

		//override :1.type, 2.write, 3.read, 4.set, 5.operator bool()
		char type()const override;
		std::ostream& write(std::ostream& os) const override;
		std::istream& read(std::istream& istr) override;
		virtual void set(int member_id);
		operator bool()const override;
		// override; => intend to override the function in base class
		void setDefault() override;
	
	};
	
	
}
#endif // !SDDS_BOOK_H

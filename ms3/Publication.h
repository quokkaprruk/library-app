#ifndef SDDS_PUBLICATION_H
#define SDDS_PUBLICATION_H
#include "Lib.h"
#include "Date.h"
#include "Streamable.h"
namespace sdds {
	//The publication class is a general encapsulation of any periodic publication.
	class Publication:public Streamable {
		//dynamic
		char* m_title;
		//fixed sz
		char m_shelfId[SDDS_SHELF_ID_LEN + 1];
		int m_membership; // 5 digit number, if number =0 means available
		int m_libRef; //This serial number is used internally to uniquely identify each publication in the system.
		Date m_date; //publish date

	public:
		
		Publication();
		
		//the rule of three
		Publication(const Publication& src);
		Publication& operator=(const Publication& src);
		~Publication();

		//modifiers
		virtual void set(int member_id);
		// Sets the membership attribute to either zero or a five-digit integer.
		void setRef(int value);
		// Sets the **libRef** attribute value
		void resetDate();
		// Sets the date to the current date of the system.

		//queries
		virtual char type()const;
		//Returns the character 'P' to identify this object as a "Publication object"
		bool onLoan()const;
		//Returns true is the publication is checkout (membership is non-zero)
		Date checkoutDate()const;
		//Returns the date attribute
		bool operator==(const char* title)const;
		//Returns true if the argument title appears anywhere in the title of the 
		//publication. Otherwise, it returns false; (use strstr() function in <cstring>)
		operator const char* ()const;
		//Returns the title attribute
		int getRef()const;
		//Returns the libRef attirbute. 

		void setDefault();
		//Streamable pure virtual function implementations
		std::ostream& write(std::ostream& os) const ;

		std::istream& read(std::istream& istr) ;

		bool conIO(std::ios& iosObj)const;

		operator bool()const ;
	

	};

}
#endif // !SDDS_PUBLICATION_H

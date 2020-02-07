#pragma once

#include "Book.h"

namespace LibrarySystem
{
	// klasa reprezentujaca ebook
	class EBook : public Book
	{
	private:

		// format ebooka
		std::string m_format;

	public:

		// Format: id;lendPrice;isAvailable(0:1);itemtype;authorId;dd-mm-yyyy;dd-mm-yyyy;release;format
		EBook(std::string stringToParse);
		// Format: id;lendPrice;isAvailable(0:1);itemtype;authorId;dd-mm-yyyy;dd-mm-yyyy;release;format
		EBook(std::vector<std::string> stringToParse);
		virtual ~EBook();

		// Format: id;lendPrice;isAvailable(0:1);itemtype;authorId;dd-mm-yyyy;dd-mm-yyyy;release;format
		virtual void ParseFromString(std::string string) override;
		// Format: id;lendPrice;isAvailable(0:1);itemtype;authorId;dd-mm-yyyy;dd-mm-yyyy;release;format
		virtual void ParseFromString(std::vector<std::string> stringVector) override;
		// konwertuje by wyswietlic string
		virtual std::string ToString() override;
		// konwertuje na csv
		virtual std::string ToCsvRecord() override;
	};
}


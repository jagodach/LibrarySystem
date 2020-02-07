#pragma once

#include "LibraryItem.h"

namespace LibrarySystem
{
	// klasa reprezentuje ksiazki
	class Book : public LibraryItem
	{

	private:

		// data wypuszczenia ksiazki
		int m_releaseVersion;

	public:

		// Format: id;lendPrice;isAvailable(0:1);itemtype;authorId;dd-mm-yyyy;dd-mm-yyyy;release
		Book(std::string stringToParse);
		// Format: id;lendPrice;isAvailable(0:1);itemtype;authorId;dd-mm-yyyy;dd-mm-yyyy;release
		Book(std::vector<std::string> stringToParse);
		virtual ~Book();

		// Format: id;lendPrice;isAvailable(0:1);itemtype;authorId;dd-mm-yyyy;dd-mm-yyyy;release
		virtual void ParseFromString(std::string string) override;
		// Format: id;lendPrice;isAvailable(0:1);itemtype;authorId;dd-mm-yyyy;dd-mm-yyyy;release
		virtual void ParseFromString(std::vector<std::string> stringVector) override;
		// konweertuje by wyswietlic strinig
		virtual std::string ToString() override;
		// konwertuje do csv
		virtual std::string ToCsvRecord() override;

	protected:

		// konstruktor domyslny
		Book() {}
	};
}


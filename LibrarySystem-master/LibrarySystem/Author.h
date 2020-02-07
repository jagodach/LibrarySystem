#pragma once

#include "FileRecord.h"
#include "Structs.h"

namespace LibrarySystem
{
	// Klasa reprezentuje autora
	class Author : public FileRecord
	{

	private:

		// typ autora
		AuthorType m_AuthorType;
		// dane autora
		PersonData m_personData;

	public:

		// Format: id;authortype;name,surname,dd-mm-yyyy
		Author(std::vector<std::string> stringToParse);
		// Format: id;authortype;name,surname,dd-mm-yyyy
		Author(std::string stringToParse);
		virtual ~Author();

		// Format: id;authortype;name,surname,dd-mm-yyyy
		virtual void ParseFromString(std::string string) override;
		// Format: id;authortype;name,surname,dd-mm-yyyy
		virtual void ParseFromString(std::vector<std::string> stringVector) override;
		// konwertuje by wyswietlic stringi
		virtual std::string ToString() override;
		// konwertuje na format csv
		virtual std::string ToCsvRecord() override;

	protected:

		// konstruktor domyslny
		Author() {}
	};

}

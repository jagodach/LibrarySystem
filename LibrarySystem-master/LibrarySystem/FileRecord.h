#pragma once

#include <string>
#include <vector>

namespace LibrarySystem
{
	//bazowa klasa dla wszystkich obiektow ktore sa zapisywane do pliku. JEst to klasa abstakcyjna- nie ma pelnej implementacji
	//uzywanie tej klasy ulatwia zapisywanie i odczytywanie danych
	class FileRecord
	{

	protected:

		// Object id - powinno byæ unikalna w bazie danych
		unsigned int m_Id;

	public:

		// zwraca object id
		int GetId() const { return m_Id; }

		// nie ma ¿adnej implementacji. Powinien parsowaæ pola obiektów z stringow,
		virtual void ParseFromString(std::string string) = 0;
		// nie ma ¿adnej implementacji. Powinien parsowaæ pola obiektów z stringow,
		virtual void ParseFromString(std::vector<std::string> stringVector) = 0;
		//nie ma ¿adnej implementacji. tworzy wyswietlanie stringow obiektow. 
		virtual std::string ToString() = 0;
		//nie ma ¿adnej implementacji. tworzy csv obiektu
		virtual std::string ToCsvRecord() = 0;
	};
}


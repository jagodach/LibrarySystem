#pragma once

#include <filesystem>
//<filesystem> w celu uzyskania dostêpu do klas i funkcji, które manipuluj¹ i pobieraj¹ informacje o œcie¿kach, plikach i katalogach
#include <fstream>
#include <string>
#include <vector>

//klasa z statycznymi metodami, odpowiada za odczytywanie/zapisywanie do pliku, rozdzielanie stringow
namespace LibrarySystem
{
	class Helpers
	{

	public:

		//Tworzy nowe ID
		static unsigned int GetNextId();
		// Ustawia startowe/pocz¹tkowe ID
		static void SetNextId(unsigned int newId);

		//Rozdziela string do tablicy poprzez nadanie separatora/rozgranicznika/delimeter
		static std::vector<std::string> SplitStringToArray(std::string stringToSplit, std::string delimiter);
		//Laczy sciezki z czesci
		static std::filesystem::path CombinePath(std::vector<std::string> pathComponents);
		//Czyta pliki z lokalizacji. Moze to byc rozny typ pliku tekstowego np txt, csv, c , cpp
		static std::vector<std::string> ReadFile(std::filesystem::path pathToFile);
		//Szablon do zapisania vektora FileRecord do pliku
		//Pozwala na nieczytanie wiele razy tego samego kodu-kompilator zrobi to za nas
		template<class T>
		static void SaveToCSVFile(std::vector<T> recordsToSave, std::filesystem::path pathToFile);
		//Szablon do konwersji wektora FileRecords w celu wyœwietlenia vektora stringow
		template<class T>
		static std::vector<std::string> ConvertToStringVector(std::vector<T> recordsToConver);
		//Szablon do usuniecia FileRecord z wektora
		//Wektor zostal podany przez referencje co oznacza ze podajemy adres wektora i uzywamy tego samego wektora ktory podajemy(to ten sam obiekt, nie tylko skopiowana wartosc)
		template<class T>
		static bool RemoveIdFromVector(std::vector<T>& recordsToConver, int id);
		template<class T>
		static void ClearAndDeallocateVector(std::vector<T>& vector);

		// Konwersja string na enum
		static enum AuthorType ConvertAuthorToEnum(std::string enumString);
		static enum ItemType ConvertItemToEnum(std::string enumString);
		static enum UserType ConvertUserTypeToEnum(std::string enumString);

		// Konwersja Enum na string
		static std::string ConvertEnumToString(ItemType itemType);
		static std::string ConvertEnumToString(AuthorType authorType);
		static std::string ConvertEnumToString(UserType userType);

		//Sprawdza czy string konczy sie z specific string. Pomaga w parsowaniu(analizowaæ ci¹g znaków w celu ustalenia jego struktury)
		static bool HasEnding(std::string const &fullString, std::string const &ending);
	};
	//Szablon dos³ownie pisze kod z ró¿nymi klasami. Sprawdza, czy sk³adnia jest mo¿liwa w czasie kompilacji.
	template<class T>
	void Helpers::SaveToCSVFile(std::vector<T> recordsToSave, std::filesystem::path pathToFile)
	{
		std::ofstream fileToSave(pathToFile);

		for (auto& record : recordsToSave)
		{
			fileToSave << record->ToCsvRecord() << std::endl;
		}

		fileToSave.close();
	}

	template<class T>//szablony dzieki nim nie trzeba definiowac typu na poczatku za t bedzie wpisany typ np m_users
	static std::vector<std::string>
		Helpers::ConvertToStringVector(std::vector<T> recordsToConver)
	{
		std::vector<std::string> records;

		for (auto& record : recordsToConver)
		{
			records.push_back(record->ToString());
		}

		return records;//zwraca wektor stringow
	}

	template<class T>//wpisujemy m_users
	static bool Helpers::RemoveIdFromVector(std::vector<T>& recordsToConver, int id)
	{
		//iterujemy, do usunecia potrzebujemy pozycji elementu w wektorze-iteratora(it) auto bo pisanie go jest ciezkie
		// std::Vector<Author*>::iterator albo auto 

		for (auto it = recordsToConver.begin(); it != recordsToConver.end(); ++it)//iterowanie po wektorze tefo co przekazalismy czyli po wektorze userow
		{
			if ((*it)->GetId() == id)//jezeli wskaznik na usera, jak znajdziemy id to usuwamy 
			{
				delete (*it);
				recordsToConver.erase(it);//zeruje wektor
				// trzeba wrocic po wykasowaniu

				return true;//jesli udalo sie usunac
			}
		}
		return false;
	}

	template<class T>
	void Helpers::ClearAndDeallocateVector(std::vector<T>& vector)
	{
		for (auto v : vector)
			delete v;
		vector.clear();
	}

}


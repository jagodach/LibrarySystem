#include "pch.h"

#include <algorithm>
#include <cstdarg>

#include "Helpers.h"
#include "Structs.h"
#include "FileRecord.h"

namespace LibrarySystem
	//rozdzielanie stringow
	//operacje na id

{
	//statyczna zmienna jest tworza raz na plik. znajduje sie tutaj poniewaz sa wykonywane na niej operacje
	//wartosc jest kopiowana i zwracana do miejsca ktore o to prosilo
	namespace Globals
	{
		static int CurrentId = 0;
	}

	
	unsigned int Helpers::GetNextId()
	{
		return ++Globals::CurrentId;//w globalnej przestrzeni currentid w dodawaniu autora
	}

	void Helpers::SetNextId(unsigned int newId)
	{
		Globals::CurrentId = newId;
	}
	//rozdziela pobrane linie ze mozliwe jest wykorzystanie tych danych zawartych w pliku
	std::vector<std::string> LibrarySystem::Helpers::SplitStringToArray(std::string stringToSplit, std::string delimiter)
	{
		stringToSplit.erase(std::remove_if(stringToSplit.begin(), stringToSplit.end(), isspace), stringToSplit.end());

		//Dodaje ogranicznik do zakoñczenia, jeœli go brakuje. jesli nie ma rozgranicznika na koncu to nie dostaniemy ostatniego elementu z stringa 
		if (!HasEnding(stringToSplit, delimiter))
		{
			stringToSplit += delimiter;
		}

		std::vector<std::string> resultArray;

	

		size_t position = 0;
		std::string token;
		// position = place of ;
		while ((position = stringToSplit.find(delimiter)) != std::string::npos)
		{
			// string from 0 to ;
			token = stringToSplit.substr(0, position);
			// save string
			resultArray.push_back(token);
			// remove string from 0 to ; + length of 
			stringToSplit.erase(0, position + delimiter.length());
		}

		return resultArray;
	}

	std::filesystem::path LibrarySystem::Helpers::CombinePath(std::vector<std::string> pathComponents)
	{
		std::filesystem::path resultPath = "";
		for (auto iterator = pathComponents.begin(); iterator != pathComponents.end(); ++iterator)
		{
			resultPath = resultPath / (*iterator).c_str();
		}
		return resultPath;
	}

	std::vector<std::string> LibrarySystem::Helpers::ReadFile(std::filesystem::path pathToFile)
	{
		std::vector<std::string> fileContent;

		std::ifstream file(pathToFile);
		if (file.is_open())
		{
			std::string line;
			while (getline(file, line))//jesli nie skonczyl sie plik pobieraj po 1 linii
			{
				fileContent.push_back(line);
			}
			file.close();
		}

		return fileContent;
	}

	AuthorType LibrarySystem::Helpers::ConvertAuthorToEnum(std::string enumString)
	{
		std::transform(enumString.begin(), enumString.end(), enumString.begin(), ::tolower);

		if (enumString == "none") return AuthorType::AT_None;
		if (enumString == "author") return AuthorType::AT_Author;
		if (enumString == "bookauthor") return AuthorType::AT_BookAuthor;
		else return AuthorType::AT_Max;
	}

	ItemType Helpers::ConvertItemToEnum(std::string enumString)
	{
		std::transform(enumString.begin(), enumString.end(), enumString.begin(), ::tolower);

		if (enumString == "none") return ItemType::IT_None;
		if (enumString == "item") return ItemType::IT_Item;
		if (enumString == "book") return ItemType::IT_Book;
		if (enumString == "ebook") return ItemType::IT_EBook;
		else return ItemType::IT_Max;
	}

	enum UserType Helpers::ConvertUserTypeToEnum(std::string enumString)
	{
		std::transform(enumString.begin(), enumString.end(), enumString.begin(), ::tolower);

		if (enumString == "none") return UserType::UT_None;
		if (enumString == "admin") return UserType::UT_Admin;
		if (enumString == "user") return UserType::UT_User;
		else return UserType::UT_Max;
	}

	bool Helpers::HasEnding(std::string const & fullString, std::string const & ending)
	{
		if (fullString.length() >= ending.length()) 
		{
			//porownuje czy ostatni char stringa jest rowny podanemu
			return (fullString.compare(fullString.length() - ending.length(), ending.length(), ending) == 0);
		}
		else 
		{
			return false;
		}
	}
	std::string Helpers::ConvertEnumToString(ItemType itemType)
	{
		switch (itemType)
		{
		case ItemType::IT_None: return "none";
		case ItemType::IT_Item: return "item";
		case ItemType::IT_Book: return "book";
		case ItemType::IT_EBook: return "ebook";
		default: return "max";
		}
	}

	std::string Helpers::ConvertEnumToString(AuthorType authorType)
	{
		switch (authorType)
		{
		case AuthorType::AT_None: return "none";
		case AuthorType::AT_Author: return "author";
		case AuthorType::AT_BookAuthor: return "bookauthor";
		default: return "max";
		}
	}

	std::string Helpers::ConvertEnumToString(UserType userType)
	{
		switch (userType)
		{
		case UserType::UT_None: return "none";
		case UserType::UT_Admin: return "admin";
		case UserType::UT_User: return "user";
		default: return "max";
		}
	}

} //LibrarySystem

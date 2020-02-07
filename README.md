# LibrarySystem
Projekt pk3 - system obslugi biblioteki

Prosty system obsługi biblioteki.
Dane przechowywane są w plikach .csv


## Przebieg aplikacji
-Ładowanie danych:
  Aplikacja ładuje dane z plików wprowadzonych na stałe (hardcoded) w rozwiązaniu. Różne typy obiektów są przechowywane w innych wektorach. Wektory posiadają tylko wskaźniki do obiektów
  
-Wiązanie danych:
  Obiekty posiadają referencje do siebie nawzajem. Przechowują tylko id w plikach z danymi. Używają ID żeby znaleźć obiekt i związać go z innymi kolekcjami.
  
-Login:

-Konsola:
  Użytkownik może wybrać różne opcje. Różni użytkownicy posiadają różne menu i funkcje w nich zawarte. Użytkownik może tylko zobaczyć dane i wypożyczyć przedmioty(np. książki).
  
  Admin może robić wszystko:
  Autorzy: dodawanie, oglądanie, usuwanie
  Użytkownicy: dodawanie, oglądanie, usuwanie
  Przedmioty: dodawanie, oglądanie, usuwanie
  
  Wypożyczenia: 
  
    -mogą być oglądane(użytkownik może zobaczyć tylko własne wypożyczenia, admin widzi wszystkie)
    
    -mogą być zwracane. Po zwróceniu przedmiotu pojawia się on w historii wypożyczeń. Użytkownik musi zapłacić za wypożyczenie(cena wypożyczenia + 10% za każdy tydzień opóźnienia)
    
    -każdy przedmiot może być wypożyczony raz(Jeśli chcemy mieć w bibliotece trzy te same książki to muszą zostać one dodane trzy razy)
    
    -zakończenie programu


## Format danych
  Dane są przechowywane w plikach tekstowych (.csv). Nie jest to czysty plik .csv. Zachowuje się jak plik tekstowy (.txt).
  Format danych liczy się tylko do zapisywania i pobierania danych.
  

## Krótkie omówienie klas i plików:
### LibrarySystem.cpp
    Plik zawierający main(). Znajduje się tam cała obsługa aplikacji/konsolii. 
### Library manager
    Klasa, która przechowuje całe dane i jest połączona z GUI. Cała "logika" aplikacji się tam znajduje.
### Helpers
    Klasa z statycznymi metodami, które wykonują podstawowe rzeczy takie jak odczytywanie/zapisaywanie plików, rozdzielanie stringów.
### Structs
    Zawiera podstawowe typy używane w aplikacji (SimpleData i PersonData).
    SimpleData jest prostym "wrapperem"( funkcje lub klasy, których zadaniem jest jedynie wywołanie innych funkcji lub metod obiektów)       ponieważ używanie funckji związanych z datą i czasem jest bardzo skomplikowane.  
    PersonData umożliwia nie dołączać wszędzie name, surname, birthday. 
### FileRecord
    Abstrakcyjna klasa, która zachowuje się jak interfejs umożliwiający odczytywanie i zapisywanie dancyh.
### LibraryItem, Book, EBook
    Przedmioty w bibliotece. LibraryItem jest podstawowym przedmiotem, reszta jest tylko po to żeby pokazać dziedziczenie.
    Book i EBook mają tylko małe różnice między sobą. Mogłoby zostać stworzone więcej przedmiotów, ale wszystkie byłyby takie same i         jest to bezcelowe.
### LendRecord
    Rezprezentuje wypożyczenia. Łączy użytkownika z przedmiotami i ustawia date i cene za wypożyczenie.

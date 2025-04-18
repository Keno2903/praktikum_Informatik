/////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXV
// Versuch 1.2: Strukturen
//
// Datei:  Strukturen.cpp
// Inhalt: Hauptprogramm
//////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>


typedef struct person {
	std::string sNachname;
	std::string sVorname;
	int iGeburtsjahr;
	int iAlter;
} Person;

void printPerson(Person nBenutzer) {
	std::cout << "Dein Name ist: " << nBenutzer.sVorname + " " + nBenutzer.sNachname << "\nDu bist " << nBenutzer.iAlter << " Jahre alt und bist im Jahr " << nBenutzer.iGeburtsjahr << " geboren" << std::endl;
}

int main()
{

    Person nBenutzer;

    std::cout << "Bitte geben sie ihren Vornamen ein: " << std::endl;
    std::cin >> nBenutzer.sVorname;

    std::cout << "Bitte geben sie ihren Nachnamen ein: " << std::endl;
    std::cin >> nBenutzer.sNachname;

    std::cout << "Bitte geben sie ihr Geburtsjahr ein: " << std::endl;
    std::cin >> nBenutzer.iGeburtsjahr;

    std::cout << "Bitte geben sie ihr Alter ein: " << std::endl;
    std::cin >> nBenutzer.iAlter;
    
    printPerson(nBenutzer);

    Person nKopieEinzeln, nKopieGesamt;

    nKopieGesamt = nBenutzer;

    nKopieEinzeln.sVorname = nBenutzer.sVorname;
    nKopieEinzeln.sNachname = nBenutzer.sNachname;
    nKopieEinzeln.iAlter = nBenutzer.iAlter;
    nKopieEinzeln.iGeburtsjahr = nBenutzer.iGeburtsjahr;

    printPerson(nKopieGesamt);
    printPerson(nKopieEinzeln);

    return 0;
}

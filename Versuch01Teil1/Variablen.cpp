//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 
// 
// Versuch 1.1: Datentypen und Typumwandlung
//
// Datei:  Variablen.cpp
// Inhalt: Hauptprogramm
//////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>

int main()
{
    int iErste = 0;
    int iZweite = 0;

    // Hier folgt Ihr eigener Code
    std::cout << "Bitte geben sie eine Zahl ein" << std::endl;
    std::cin >> iErste;

    std::cout << "Bitte geben sie noch eine Zahl ein" << std::endl;
    std::cin >> iZweite;

    int iSumme = iErste + iZweite;
    int iQuotient = iErste / iZweite; // Ganzzahlige Division
    std::cout << "Ganzzahlige Berechnungen:" << std::endl;
    std::cout << "Summe: " << iSumme << std::endl;
    std::cout << "Quotient (ganzzahlig): " << iQuotient << std::endl;

    // Aufgabe 2: Berechnungen mit double Variablen
    double dSumme = iErste + iZweite;
    double dQuotient = iErste / iZweite; // Division von int-Werten liefert hier immer noch einen ganzzahligen Wert
    std::cout << "\nBerechnungen mit double Variablen (ohne Typecasting):" << std::endl;
    std::cout << "Summe: " << dSumme << std::endl;
    std::cout << "Quotient: " << dQuotient << std::endl;

    // Aufgabe 3: Berechnungen mit explizitem Typecasting
    double dSummeCast = (double) iErste + iZweite;
    double dQuotientCast = (double)(iErste)/(iZweite);
    std::cout << "\nBerechnungen mit explizitem Typecasting:" << std::endl;
    std::cout << "Summe: " << dSummeCast << std::endl;
    std::cout << "Quotient: " << dQuotientCast << std::endl;

    // Erklärung:
    // Ohne explizites Typecasting wird bei der Division von zwei int-Werten der Nachkommateil abgeschnitten.
    // Durch das explizite Typecasting erfolgt die Division als Gleitkommadivision, wodurch Nachkommastellen erhalten bleiben.

    // Aufgabe 4: Eingabe und Ausgabe von Vor- und Nachname
    std::string sVorname, sNachname;
    std::cout << "\nBitte geben Sie Ihren Vornamen ein: ";
    std::cin >> sVorname;
    std::cout << "Bitte geben Sie Ihren Nachnamen ein: ";
    std::cin >> sNachname;

    std::string sVornameName = sVorname + " " + sNachname;
    std::string sNameVorname = sNachname + ", " + sVorname;
    std::cout << "\nName in der Form \"Vorname Nachname\": " << sVornameName << std::endl;
    std::cout << "Name in der Form \"Nachname, Vorname\": " << sNameVorname << std::endl;

    // Aufgabe 5:
    {
    	int iFeld[2] = {1,2};
    	int spielFeld[2][3] = {{1,2,3},{1,2,3}};
    	const int iZweite = 1;

    	std::cout << iFeld[0] << std::endl;
    	std::cout << iFeld[1] << std::endl;

    	std::cout << spielFeld[0][0] << " " << spielFeld[0][1] << " " << spielFeld[0][2] << std::endl;
    	std::cout << spielFeld[1][0] << " " << spielFeld[1][1] << " " << spielFeld[1][2] << std::endl;

    	std::cout << iZweite << std::endl;

    }
    std::cout << iZweite << std::endl;


    // Aufgabe 6:
    int iName1, iName2;

    iName1 = (int) sVorname[0];
    iName2 = (int) sVorname[1];

    std::cout << "Der erste Buchstabe des Vornamens als Zahl ist: " << iName1 << std::endl;
    std::cout << "Der zweite Buchstabe des Vornamens als Zahl ist: " << iName2 << std::endl;

    // Aufgabe 7:

    //ASCII unterscheidet zwischen Groß- und Kleinbuchstaben

    int positionInAlphabet1 = iName1 > 97 ? iName1 % 96 : iName1 % 64;
    int positionInAlphabet2 = iName2 > 97 ? iName2 % 96 : iName2 % 64;

    std::cout << "Die Position im Alphabet des ersten Buchstabens des Vornamens ist: " << positionInAlphabet1 << std::endl;
    std::cout << "Die Position im Alphabet des zweiten Buchstabens des Vornamens ist: " << positionInAlphabet2 << std::endl;

    return 0;
    
}

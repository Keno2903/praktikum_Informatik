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

    return 0;


    return 0;
    
}

/** @mainpage
 *
 * Praktikum Informatik 1 MMXXV <BR>
 * Versuch 5: Dynamische Datenstrukturen
 *
 */

#include <iostream>
#include <vector>      // CHANGED: use std::vector instead of custom Liste
#include <fstream>     // CHANGED: for file I/O
#include <string>
#include "Student.h"

int main() {
    // CHANGED: replaced Liste studentenListe; with std::vector<Student>
    std::vector<Student> studentenListe;
    Student student;
    char abfrage;

    std::cout << "Wollen Sie die Liste selbst fuellen? (j)/(n) ";
    std::cin >> abfrage;
    std::cin.ignore(1, '\n'); // CHANGED: ignore single '\n' after reading abfrage

    if (abfrage != 'j') {
        // CHANGED: use push_back statt pushBack
        studentenListe.push_back(Student(34567, "Harro Simoneit",   "19.06.1971", "Am Markt 1"));
        studentenListe.push_back(Student(74567, "Vera Schmitt",      "23.07.1982", "Gartenstr. 23"));
        studentenListe.push_back(Student(12345, "Siggi Baumeister",  "23.04.1983", "Ahornst.55"));
        studentenListe.push_back(Student(64567, "Paula Peters",      "9.01.1981",  "Weidenweg 12"));
        studentenListe.push_back(Student(23456, "Walter Rodenstock", "15.10.1963","Wüllnerstr.9"));
    }

    do {
        std::cout << "\nMenue:\n"
                  << "-----------------------------\n"
                  << "(1): Datenelement hinten hinzufuegen\n"
                  << "(2): Datenelement vorne entfernen\n"
                  << "(3): Datenbank ausgeben\n"
                  << "(4): Datenbank in umgekehrter Reihenfolge ausgeben\n"
                  << "(5): Datenelement loeschen\n"
                  << "(6): Datenelement vorne hinzufuegen\n"
                  << "(7): Daten aus Datei einlesen\n"       // NEW
                  << "(8): Daten in Datei sichern\n"         // NEW
                  << "(0): Beenden\n";
        std::cin >> abfrage;
        std::cin.ignore(1, '\n'); // CHANGED: ignore single '\n' after reading abfrage

        switch (abfrage) {

            case '1': { // hinten hinzufuegen
                unsigned int matNr;
                std::string name, geburtstag, adresse;
                std::cout << "Name: ";            std::getline(std::cin, name);
                std::cout << "Geburtsdatum: ";    std::getline(std::cin, geburtstag);
                std::cout << "Adresse: ";         std::getline(std::cin, adresse);
                std::cout << "Matrikelnummer: ";  std::cin >> matNr;
                std::cin.ignore(1, '\n');         // CHANGED: ignore single '\n' after matNr
                // CHANGED: push_back statt pushBack
                studentenListe.push_back(Student(matNr, name, geburtstag, adresse));
            } break;

            case '2': { // vorne entfernen
                if (!studentenListe.empty()) {
                    // CHANGED: front() statt dataFront()
                    Student tmp = studentenListe.front();
                    std::cout << "Gelöscht: "; tmp.ausgabe();
                    // CHANGED: erase(begin) statt popFront()
                    studentenListe.erase(studentenListe.begin());
                } else {
                    std::cout << "Die Liste ist leer!\n";
                }
            } break;

            case '3': // ausgabe vorwärts
                if (!studentenListe.empty()) {
                    std::cout << "Inhalt fortlaufend:\n";
                    // CHANGED: iterator statt ausgabeVorwaerts()
                    for (auto it = studentenListe.cbegin(); it != studentenListe.cend(); ++it)
                        it->ausgabe();
                } else {
                    std::cout << "Die Liste ist leer!\n";
                }
                break;

            case '4': // ausgabe rückwärts
                if (!studentenListe.empty()) {
                    std::cout << "Inhalt rückwärts:\n";
                    // CHANGED: reverse_iterator statt ausgabeRueckwaerts()
                    for (auto it = studentenListe.crbegin(); it != studentenListe.crend(); ++it)
                        it->ausgabe();
                } else {
                    std::cout << "Die Liste ist leer!\n";
                }
                break;

            case '5': { // Datenelement löschen (ohne <algorithm>)
                if (!studentenListe.empty()) {
                    unsigned int mtr;
                    std::cout << "Matrikelnummer des zu loeschenden Studenten: ";
                    std::cin >> mtr;
                    std::cin.ignore(1, '\n'); // CHANGED: ignore single '\n' after mtr

                    // CHANGED: manuelle Suche und Löschen
                    bool gefunden = false;
                    for (std::vector<Student>::iterator it = studentenListe.begin(); it != studentenListe.end(); ++it) {
                        if (it->getMatNr() == mtr) {
                            studentenListe.erase(it);
                            std::cout << "Student mit Matrikelnummer " << mtr << " gelöscht.\n";
                            gefunden = true;
                            break; // wichtig: Vektor geändert, Schleife beenden
                        }
                    }
                    if (!gefunden) {
                        std::cout << "Kein Student mit Matrikelnummer " << mtr << " gefunden.\n";
                    }
                } else {
                    std::cout << "Die Liste ist leer!\n";
                }
            } break;

            case '6': { // vorne hinzufügen
                unsigned int matNr;
                std::string name, geburtstag, adresse;
                std::cout << "Name: ";            std::getline(std::cin, name);
                std::cout << "Geburtsdatum: ";    std::getline(std::cin, geburtstag);
                std::cout << "Adresse: ";         std::getline(std::cin, adresse);
                std::cout << "Matrikelnummer: ";  std::cin >> matNr;
                std::cin.ignore(1, '\n');         // CHANGED: ignore single '\n' after matNr
                // CHANGED: insert(begin) statt pushFront()
                studentenListe.insert(studentenListe.begin(),
                                      Student(matNr, name, geburtstag, adresse));
            } break;

            case '7': { // Daten aus Datei einlesen
                std::string filename;
                std::cout << "Dateiname zum Einlesen: ";
                std::getline(std::cin, filename);
                std::ifstream in(filename); // CHANGED
                if (!in) {
                    std::cerr << "Fehler beim Öffnen der Datei.\n";
                    break;
                }
                studentenListe.clear(); // CHANGED: alte Daten löschen
                unsigned int matNr;
                std::string name, geburtstag, adresse;
                // CHANGED: semikolon-getrenntes Einlesen
                while (in >> matNr) {
                    in.ignore(1, ';');
                    std::getline(in, name, ';');
                    std::getline(in, geburtstag, ';');
                    std::getline(in, adresse);
                    studentenListe.emplace_back(matNr, name, geburtstag, adresse);
                }
                in.close(); // CHANGED
                std::cout << "Daten eingelesen.\n";
            } break;

            case '8': { // Daten in Datei sichern
                std::string filename;
                std::cout << "Dateiname zum Sichern: ";
                std::getline(std::cin, filename);
                std::ofstream out(filename); // CHANGED
                if (!out) {
                    std::cerr << "Fehler beim Anlegen der Datei.\n";
                    break;
                }
                // CHANGED: Bereichs-for-Schleife für Ausgabe
                for (const auto& s : studentenListe) {
                    out << s.getMatNr()      << ';'
                        << s.getName()       << ';'
                        << s.getGeburtstag() << ';'
                        << s.getAdresse()    << '\n';
                }
                out.close(); // CHANGED
                std::cout << "Daten gesichert.\n";
            } break;

            case '0':
                std::cout << "Programm beendet.\n";
                break;

            default:
                std::cout << "Ungültige Eingabe, bitte erneut.\n";
                break;
        }
    } while (abfrage != '0');

    return 0;
}

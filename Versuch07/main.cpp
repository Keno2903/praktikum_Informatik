/** @mainpage
 *
 * Praktikum Informatik 1 MMXXV <BR>
 * Versuch 5: Dynamische Datenstrukturen
 *
 */
#include <iostream>
#include <vector>      // use std::vector instead of custom Liste
#include <fstream>     // for file I/O
#include <string>
#include <algorithm>   // for std::sort, std::find
#include "Student.h"

int main() {
    std::vector<Student> studentenListe;
    Student student;
    char abfrage;

    std::cout << "Wollen Sie die Liste selbst fuellen? (j)/(n) ";
    std::cin >> abfrage;
    std::cin.ignore(1, '\n'); // ignore single '\n' after reading abfrage

    if (abfrage != 'j') {
        studentenListe.push_back(Student(34567, "Harro Simoneit",   "19.06.1971", "Am Markt 1"));
        studentenListe.push_back(Student(74567, "Vera Schmitt",      "23.07.1982", "Gartenstr. 23"));
        studentenListe.push_back(Student(12345, "Siggi Baumeister",  "23.04.1983", "Ahornst.55"));
        studentenListe.push_back(Student(64567, "Paula Peters",      "09.01.1981", "Weidenweg 12"));
        studentenListe.push_back(Student(23456, "Walter Rodenstock", "15.10.1963", "Wüllnerstr.9"));
    }

    do {
        std::cout << "\nMenue:\n"
                  << "-----------------------------\n"
                  << "(1): Datenelement hinten hinzufuegen\n"
                  << "(2): Datenelement vorne entfernen\n"
                  << "(3): Datenbank ausgeben\n"
                  << "(4): Datenbank in umgekehrter Reihenfolge ausgeben\n"
                  << "(5): Datenelement loeschen (find & erase)\n"
                  << "(6): Datenelement vorne hinzufuegen\n"
                  << "(7): Daten aus Datei einlesen\n"
                  << "(8): Daten in Datei sichern\n"
                  << "(9): Liste sortieren\n"
                  << "(0): Beenden\n";
        std::cin >> abfrage;
        std::cin.ignore(1, '\n'); // ignore single '\n'

        switch (abfrage) {

            case '1': { // hinten hinzufuegen
                unsigned int matNr;
                std::string name, geburtstag, adresse;
                std::cout << "Name: ";            std::getline(std::cin, name);
                std::cout << "Geburtsdatum: ";    std::getline(std::cin, geburtstag);
                std::cout << "Adresse: ";         std::getline(std::cin, adresse);
                std::cout << "Matrikelnummer: ";  std::cin >> matNr;
                std::cin.ignore(1, '\n');
                studentenListe.push_back(Student(matNr, name, geburtstag, adresse));
            } break;

            case '2': { // vorne entfernen
                if (!studentenListe.empty()) {
                    Student tmp = studentenListe.front();
                    std::cout << "Gelöscht: " << tmp << '\n';
                    studentenListe.erase(studentenListe.begin());
                } else {
                    std::cout << "Die Liste ist leer!\n";
                }
            } break;

            case '3': { // ausgabe vorwärts
                if (!studentenListe.empty()) {
                    std::cout << "Inhalt fortlaufend:\n";
                    for (auto it = studentenListe.cbegin(); it != studentenListe.cend(); ++it)
                        std::cout << *it << '\n';
                } else {
                    std::cout << "Die Liste ist leer!\n";
                }
            } break;

            case '4': { // ausgabe rückwärts
                if (!studentenListe.empty()) {
                    std::cout << "Inhalt rückwärts:\n";
                    for (auto it = studentenListe.crbegin(); it != studentenListe.crend(); ++it)
                        std::cout << *it << '\n';
                } else {
                    std::cout << "Die Liste ist leer!\n";
                }
            } break;

            case '5': { // Datenelement löschen mit std::find
                if (!studentenListe.empty()) {
                    unsigned int mtr;
                    std::cout << "Matrikelnummer des zu loeschenden Studenten: ";
                    std::cin >> mtr;
                    std::cin.ignore(1, '\n');

                    auto it = std::find(
                        studentenListe.begin(), studentenListe.end(),
                        Student(mtr, "", "", "")
                    );
                    if (it != studentenListe.end()) {
                        std::cout << "Gelöscht: " << *it << '\n';
                        studentenListe.erase(it);
                        std::cout << "Aktuelle Liste:\n";
                        for (auto const& s : studentenListe)
                            std::cout << s << '\n';
                    } else {
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
                std::cin.ignore(1, '\n');
                studentenListe.insert(studentenListe.begin(),
                                      Student(matNr, name, geburtstag, adresse));
            } break;

            case '7': { // Daten aus Datei einlesen
                std::string filename;
                std::cout << "Dateiname zum Einlesen: ";
                std::getline(std::cin, filename);
                std::ifstream in(filename);
                if (!in) {
                    std::cerr << "Fehler beim Öffnen der Datei.\n";
                    break;
                }
                studentenListe.clear();
                unsigned int matNr;
                std::string name, geburtstag, adresse;
                while (in >> matNr) {
                    in.ignore(1, ';');
                    std::getline(in, name, ';');
                    std::getline(in, geburtstag, ';');
                    std::getline(in, adresse);
                    studentenListe.emplace_back(matNr, name, geburtstag, adresse);
                }
                in.close();
                std::cout << "Daten eingelesen.\n";
            } break;

            case '8': { // Daten in Datei sichern
                std::string filename;
                std::cout << "Dateiname zum Sichern: ";
                std::getline(std::cin, filename);
                std::ofstream out(filename);
                if (!out) {
                    std::cerr << "Fehler beim Anlegen der Datei.\n";
                    break;
                }
                for (const auto& s : studentenListe) {
                    out << s.getMatNr()      << ';'
                        << s.getName()       << ';'
                        << s.getGeburtstag() << ';'
                        << s.getAdresse()    << '\n';
                }
                out.close();
                std::cout << "Daten gesichert.\n";
            } break;

            case '9': { // Liste sortieren
                if (!studentenListe.empty()) {
                    std::sort(studentenListe.begin(), studentenListe.end());
                    std::cout << "Liste sortiert nach Matrikelnummer:\n";
                    for (auto const& s : studentenListe)
                        std::cout << s << '\n';
                } else {
                    std::cout << "Die Liste ist leer!\n";
                }
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

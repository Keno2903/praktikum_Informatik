/*
 * Buch.cpp
 *
 *  Created on: 23.04.2025
 *      Author: kenogollner
 */

#include "Buch.h"
#include "Medium.h"

Buch::Buch(std::string initTitel, std::string initAutor) : Medium(initTitel), autor(initAutor)
{
}

Buch::~Buch() {
	// TODO Auto-generated destructor stub
}

void Buch::ausgabe(std::ostream& os) const {
    // Basisdaten ausgeben und dann Autor ergänzen
    Medium::ausgabe(os);
    os << "Autor: " << autor << std::endl;
}

bool Buch::ausleihen(Person person, Datum ausleihdatum) {
    // Keine speziellen Ausleihbeschränkungen für Bücher -> Basisklassen-Logik verwenden
    return Medium::ausleihen(person, ausleihdatum);
}

/*
 * DVD.cpp
 *
 *  Created on: 23.04.2025
 *      Author: kenogollner
 */

#include "DVD.h"
#include "Medium.h"

DVD::DVD(std::string initTitel, int initAltersfreigabe, std::string initGenre)
: Medium(initTitel), altersfreigabe(initAltersfreigabe), genre(initGenre)
{
}

DVD::~DVD() {
	// TODO Auto-generated destructor stub
}

void DVD::ausgabe(std::ostream& os) const {
    Medium::ausgabe(os);
    os << "FSK: ab " << altersfreigabe << " Jahre" << std::endl;
    os << "Genre: " << genre << std::endl;
}

bool DVD::ausleihen(Person person, Datum ausleihdatum) {
    // Altersbeschränkung prüfen
    // Differenz in Monaten zwischen Ausleihdatum und Geburtsdatum -> in Jahre umrechnen
    int alterMonate = ausleihdatum - person.getGeburtsdatum();
    int alterJahre = alterMonate / 12;
    if (alterJahre < altersfreigabe) {
        std::cout << "Die DVD \"" << titel << "\" kann nicht an " << person.getName()
                  << " ausgeliehen werden, da die Altersfreigabe (FSK ab "
                  << altersfreigabe << " Jahre) nicht erfüllt ist." << std::endl;
        return false;
    }
    // Sonst Basisklassen-Ausleihe durchführen
    return Medium::ausleihen(person, ausleihdatum);
}

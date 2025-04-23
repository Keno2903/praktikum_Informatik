/*
 * Magazin.cpp
 *
 *  Created on: 23.04.2025
 *      Author: kenogollner
 */

#include "Magazin.h"
#include "Medium.h"
#include "Datum.h"

Magazin::Magazin(std::string initTitel, Datum initDatumausgabe,
		std::string initSparte) :
		Medium(initTitel), datumAusgabe(initDatumausgabe), sparte(initSparte) {
}

Magazin::~Magazin() {
	// TODO Auto-generated destructor stub
}

void Magazin::ausgabe(std::ostream& os) const {
    Medium::ausgabe(os);
    os << "Ausgabe: " << datumAusgabe << std::endl;
    os << "Sparte: " << sparte << std::endl;
}

bool Magazin::ausleihen(Person person, Datum ausleihdatum) {
    // Prüfen, ob es sich um die neueste datumAusgabe handelt (Differenz in Monaten = 0)&#8203;:contentReference[oaicite:12]{index=12}
    int diffMonate = ausleihdatum - datumAusgabe;  // Operator- gibt Abstand in ganzen Monaten
    if (diffMonate == 0) {
        std::cout << "Das Magazin \"" << titel
                  << "\" ist die neueste Ausgabe und kann nicht ausgeliehen werden." << std::endl;
        return false;
    }
    // Sonst Ausleihe über Basisklasse durchführen
    return Medium::ausleihen(person, ausleihdatum);
}

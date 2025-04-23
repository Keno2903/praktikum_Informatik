/*
 * Magazin.h
 *
 *  Created on: 23.04.2025
 *      Author: kenogollner
 */

#ifndef MAGAZIN_H_
#define MAGAZIN_H_

#include "Medium.h"
#include "Datum.h"

class Magazin : public Medium{
public:
	Magazin(std::string initTitel, Datum initDatumausgabe,
			std::string initSparte);
	virtual ~Magazin();

	virtual void ausgabe(std::ostream& os) const;
	virtual bool ausleihen(Person person, Datum ausleihdatum);

	std::string sparte;
	Datum datumAusgabe;

};

#endif /* MAGAZIN_H_ */

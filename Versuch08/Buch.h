/*
 * Buch.h
 *
 *  Created on: 23.04.2025
 *      Author: kenogollner
 */

#ifndef BUCH_H_
#define BUCH_H_

#include "Medium.h"

class Buch : public Medium {
public:
	Buch(std::string initTitel, std::string initAutor);
	virtual ~Buch();

	virtual void ausgabe(std::ostream& os) const;
	virtual bool ausleihen(Person person, Datum ausleihdatum);

private:
	std::string autor;
};

#endif /* BUCH_H_ */

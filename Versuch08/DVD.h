/*
 * DVD.h
 *
 *  Created on: 23.04.2025
 *      Author: kenogollner
 */

#ifndef DVD_H_
#define DVD_H_

#include "Medium.h"
#include <string>
#include <iostream>

class DVD : public Medium {
public:
	DVD(std::string initTitel, int initAltersfreigabe, std::string initGenre);
	virtual ~DVD();

	int altersfreigabe;
	std::string genre;
	virtual void ausgabe(std::ostream& os) const;
	virtual bool ausleihen(Person person, Datum ausleihdatum);
};

#endif /* DVD_H_ */

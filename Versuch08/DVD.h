/*
 * DVD.h
 *
 *  Created on: 23.04.2025
 *      Author: kenogollner
 */

#ifndef DVD_H_
#define DVD_H_

#include <Medium.h>
#include <string>
#include <iostream>

class DVD : public Medium {
public:
	DVD(std::string initTitel, int initAltersfreigabe, std::string initGenre);
	virtual ~DVD();
};

#endif /* DVD_H_ */

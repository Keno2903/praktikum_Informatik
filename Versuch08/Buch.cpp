/*
 * Buch.cpp
 *
 *  Created on: 23.04.2025
 *      Author: kenogollner
 */

#include "Buch.h"
#include "Medium.h"

Buch::Buch(std::string initTitel, std::string initAutor) : titel(initTitel), autor(initAutor)
{
}

Buch::~Buch() {
	// TODO Auto-generated destructor stub
}

void Medium::ausgabe() const
{
	Medium::ausgabe();
	std::cout << "--> Autor ist: " << autor << std::endl;
}

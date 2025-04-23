/*!
 * Praktikum Informatik 1 
 * 
 *
 * @file Medium.cpp
 */
 
#include "Medium.h"

#include <string>
#include <iostream>

unsigned int Medium::currentID = 1;

Medium::Medium(std::string initTitel)
: titel(initTitel)
, status(false)
{
    ID = currentID++;
}

Medium::~Medium(void)
{
}

void Medium::ausgabe(std::ostream& os) const {
    os << "ID: " << ID << std::endl;
    os << "Titel: " << titel << std::endl;
    if (status) {
        os << "Status: Das Medium ist seit dem " << datumAusgeliehen
           << " an " << personAusgeliehen.getName() << " ausgeliehen." << std::endl;
    } else {
        os << "Status: Medium ist zurzeit nicht verliehen." << std::endl;
    }
}

bool Medium::ausleihen(Person person,Datum ausleihdatum)
{
    if (status)
    {
        std::cout << "Das Medium \"" << titel << "\" ist bereits verliehen!" << std::endl;
        return false;
    }
    else
    {
        status = true;
        personAusgeliehen = person;
        datumAusgeliehen = ausleihdatum;
        std::cout << "Das Medium \"" << titel << "\" wird an " << person.getName() << " verliehen." << std::endl;
        return true;
    }
}

void Medium::zurueckgeben()
{
    if (status)
    {
        status = false;
        std::cout << "Das Medium \"" << titel << "\" wurde zur�ckgegeben." << std::endl;
    }
    else
    {
        std::cout << "Das Medium \"" << titel << "\" ist nicht verliehen!" << std::endl;
    }
}

unsigned int Medium::getID()
{
    return ID;
}

bool Medium::istAusgeliehen() const {
    return status;
}

/* Ausgabeoperator << überlädt die Ausgabe für Medium und ruft die Ausgabemethode auf */
std::ostream& operator<<(std::ostream& os, const Medium& medium) {
    medium.ausgabe(os);
    return os;
}


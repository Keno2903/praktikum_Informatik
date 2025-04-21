//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXV
//////////////////////////////////////////////////////////////////////////////
#include "Student.h"


// Standard- und Parameterkonstruktor
Student::Student() :
		matNr(0), name(""), geburtstag(""), adresse("") {
}

Student::Student(unsigned int m, const std::string &n, const std::string &g,
		const std::string &a) :
		matNr(m), name(n), geburtstag(g), adresse(a) {
}

// Getter
unsigned int Student::getMatNr() const {
	return matNr;
}
std::string Student::getName() const {
	return name;
}
std::string Student::getGeburtstag() const {
	return geburtstag;
}
std::string Student::getAdresse() const {
	return adresse;
}

// Ausgabe in einen beliebigen ostream
void Student::ausgabe(std::ostream &out) const {
	out << name << ", MatNr. " << matNr << ", geb. am " << geburtstag
			<< ", wohnhaft in " << adresse;
}

// Operator==, < und > vergleichen nur die Matrikelnummer
bool Student::operator==(Student const &o) const {
	return matNr == o.matNr;
}
bool Student::operator<(Student const &o) const {
	return matNr < o.matNr;
}
bool Student::operator>(Student const &o) const {
	return matNr > o.matNr;
}

// globaler Stream-Operator: ermöglicht "std::cout << student;"
std::ostream& operator<<(std::ostream &out, Student const &s) {
	s.ausgabe(out);
	return out;
}

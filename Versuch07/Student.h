//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXV
//////////////////////////////////////////////////////////////////////////////

#ifndef STUDENT_H_
#define STUDENT_H_

#include <string>
#include <ostream>  // für std::ostream

class Student {
public:
	Student();
	Student(unsigned int matNr, const std::string &name,
			const std::string &geburtstag, const std::string &adresse);

	unsigned int getMatNr() const;
	std::string getName() const;
	std::string getGeburtstag() const;
	std::string getAdresse() const;

	// CHANGED: Ausgabe-Methode nimmt nun einen ostream& entgegen
	void ausgabe(std::ostream &out) const;

	// CHANGED: Operatorenüberladung, alle const
	bool operator==(Student const &other) const;
	bool operator<(Student const &other) const;
	bool operator>(Student const &other) const;

private:
	unsigned int matNr;
	std::string name;
	std::string geburtstag;
	std::string adresse;
};

// CHANGED: globale Überladung von operator<<
std::ostream& operator<<(std::ostream &out, Student const &s);

#endif // STUDENT_H_

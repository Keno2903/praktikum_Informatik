//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXV
//////////////////////////////////////////////////////////////////////////////

#include "Liste.h"

/**
 * @brief Standardkonstruktor, der eine leere Liste erstellt
 */
Liste::Liste() :
		front(nullptr), back(nullptr) {
}

/**
 * @brief Hinzufuegen eines neuen Listenelements am Ende der Liste.
 *
 * @param pData Zeiger auf ein Objekt der Klasse Student
 * @return void
 */
void Liste::pushBack(Student pData) {
	ListenElement *neuesElement = new ListenElement(pData, nullptr, nullptr);

	if (front == nullptr)                                       // Liste leer?
	{
		front = neuesElement;
		back = neuesElement;
	} else {
		neuesElement->setPrev(back);
		back->setNext(neuesElement);
		back = neuesElement;
	}
}

/**
 * @brief Entfernen eines Listenelements am Anfang der Liste.
 *
 * @return void
 */
void Liste::popFront() {
	ListenElement *cursor = front;

	if (front == back)                    // Liste enth�lt nur ein Listenelement
			{
		delete front;                                   // Listenelement l�schen
		front = nullptr;
		back = nullptr;
	} else {
		front = front->getNext();
		front->setPrev(nullptr);
		delete cursor;
	}
}

/**
 * @brief Entfernen eines Listenelements
 *
 * @return void
 */
void Liste::deleteElement(unsigned int mtr) {
	ListenElement *cursor = front;

	bool deleted = false;
	if (front == back)                    // Liste enth�lt nur ein Listenelement
			{
		if (front->getData().getMatNr() == mtr) {
			delete front;                               // Listenelement l�schen
			front = nullptr;
			back = nullptr;
			deleted = true;
		}
	} else {
		while (cursor != nullptr) {
			if (cursor->getData().getMatNr() == mtr) {
				std::cout << "Folgender Student wurde erfolgreich gelöscht"
						<< std::endl;
				cursor->getData().ausgabe();
				deleted = true;

				if (cursor == front) {
					popFront();
				} else if (cursor == back) {
					ListenElement *prevElement = cursor->getPrev();
					prevElement->setNext(nullptr); //der 'next' Zeiger vom vorletzten Element zeigt auf nullptr
					back = prevElement; //back Zeiger zeigt auf das vorletzte Element
					delete cursor;
				} else {
					cursor->getNext()->setPrev(cursor->getPrev());
					cursor->getPrev()->setNext(cursor->getNext());
					delete cursor; // Ruft Destruktor auf und gibt dann den Speicher wieder frei
				}
			}
			cursor = cursor->getNext();
		}

		if (!deleted) {
			std::cout << "Löschen fehlgeschlagen, Student wurde nicht gefunden"
					<< std::endl;
		}
	}
}

/**
 * @brief Hinzufuegen eines neuen Listenelements am Anfang der Liste.
 *
 * @param pData Zeiger auf ein Objekt der Klasse Student
 * @return void
 */
void Liste::pushFront(Student pData) {
	ListenElement *neuesElement = new ListenElement(pData, nullptr, nullptr);

	if (front == nullptr)                                       // Liste leer?
	{
		front = neuesElement;
		back = neuesElement;
	} else {
		neuesElement->setNext(front);
		front->setPrev(neuesElement);
		front = neuesElement;
	}
}

/**
 * @brief Pruefen, ob die Liste leer ist
 *
 * @return wenn leer true, sonst false
 */
bool Liste::empty() {
	if (front == nullptr) {
		return true;
	}
	return false;
}

/**
 * @brief Gibt die Daten des ersten Listenelements in der Liste zurueck
 *
 * @return Zeiger auf ein Objekt der Klasse Student
 */
Student Liste::dataFront() {
	return front->getData();
}

/**
 * @brief Ausgabe der Liste vom ersten bis zum letzten Element.
 *
 * @return void
 */
void Liste::ausgabeVorwaerts() const {
	ListenElement *cursor = front;

	while (cursor != nullptr) {
		cursor->getData().ausgabe();
		cursor = cursor->getNext();
	}
}

/**
 * @brief Ausgabe der Liste vom letzten bis zum ersten Element.
 *
 * @return void
 */
void Liste::ausgabeRueckwaerts() const {
	ListenElement *cursor = back;

	while (cursor != nullptr) {
		cursor->getData().ausgabe();
		cursor = cursor->getPrev();
	}
}

/**
 * @file main.cpp
 * @brief Hauptprogramm zur Berechnung der maximalen Sichtweite auf einer kugelförmigen Erde.
 *
 * Dieses Programm verwendet ausschließlich Vektoroperationen, um zu bestimmen,
 * wie weit eine Person von einem erhöhten Aussichtspunkt (557.4 m über der Erdoberfläche)
 * sehen kann, bevor die Erdkrümmung die Sicht blockiert. Dabei wird die Rotation eines
 * Erdpunktes simuliert, bis der Sichtstrahl tangential zur Erdoberfläche verläuft.
 */

#include "Vektor.h"

/**
 * @brief Hauptfunktion zur Durchführung der Horizontberechnung.
 *
 * Die Funktion initialisiert Vektoren für die Erdoberfläche und die Augenhöhe der beobachtenden Person.
 * Anschließend wird iterativ ein Punkt auf der Erdoberfläche um die Z-Achse gedreht, bis der
 * Sichtvektor zum tangentialen Punkt führt. Die Ergebnisse werden formatiert ausgegeben.
 *
 * @return int Rückgabewert 0 bei erfolgreicher Ausführung.
 */
int main()
{
	 // Vektor vom Erdmittelpunkt zur Erdoberfläche (6371 km)
    Vektor erdRadius(0, 6371, 0);

    // Vektor vom Erdmittelpunkt zur Augenhöhe (6371 km + 557.4 m)
    Vektor aussichtsPunkt(0, 6371.5574, 0);

    // Vektor für die Sichtlinie
    Vektor sicht(0, 0, 0);

    double winkelZwischenSichtUndRadius = 180; // Startwinkel (180°)
    double winkelBeta = -0.00000001; // Kleiner Rotationswinkel (Uhrzeigersinn)
    int anzahlSchritte = 0; // Zähler für die Rotationsschritte

    // Iterative Drehung des Erdpunktes, bis der Sichtwinkel ≤ 90° ist (tangential)
    while (winkelZwischenSichtUndRadius > 90)
    {
    	erdRadius.rotiereUmZ(winkelBeta); // Drehe Erdpunkt leicht im Uhrzeigersinn
      	sicht = erdRadius.sub(aussichtsPunkt); // Berechne Sichtvektor vom Auge zum Erdpunkt
      	winkelZwischenSichtUndRadius = sicht.winkel(erdRadius); // Berechne Winkel zur Erdachse
      	anzahlSchritte ++; // Erhöhe Schrittzähler
    }

    // Länge des finalen Sichtvektors = maximale Sichtweite (in km)
    double entfernung = sicht.laenge();

    // Ausgabe im gewünschten Format
    std::cout << std::fixed;
    std::cout << std::setprecision(4);

    std::cout << "Sie koennen " << entfernung << " Km weit sehen." << std::endl;
    std::cout << "Sie sind 557.4000 Meter hoch." << std::endl;
    std::cout << "Der Winkel betraegt " << anzahlSchritte * winkelBeta *180/M_PI * -1 << " Grad." << std::endl; // *-1 denn winkelBeta ist in Uhrzeigersinn
    std::cout << "Anzahl Schritte: " << anzahlSchritte << std::endl;

    return 0;

}

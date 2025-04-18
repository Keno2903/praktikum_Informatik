//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXV
// Versuch 04: Einführung Klasse
//
// Datei:  main.cpp
// Inhalt: Hauptprogramm
//////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <cmath>
#include <iomanip>
#include "Vektor.h"

/// Erdradius der idealisierten Kugel-Erde in Metern.
const double R = 6371e3;
/// Höhe der Beobachtungsplattform über dem Erdrand in Metern.
const double h = 555.7;

/**
 * @brief Hauptprogramm zur Berechnung der Sichtweite bis zum Horizont.
 *
 * Zunächst werden zwei Beispiel-Vektoren ausgegeben, um die Klasse Vektor zu testen.
 * Anschließend wird mithilfe eines iterativen Rotationsverfahrens der maximale
 * Sichtstrahl bestimmt, der die Kugel (Erde) gerade noch tangential berührt.
 *
 * @return 0 bei normalem Programmende.
 */
int main()
{
    // ------------------------------------------------------------------------
    // 1. Test der Vektor-Klasse
    // ------------------------------------------------------------------------
    // Wir erzeugen zwei Einheitsvektoren entlang der x- und y-Achse
    Vektor vector1(1.0, 0.0, 0.0);  // Einheit in +x‑Richtung
    Vektor vector2(0.0, 1.0, 0.0);  // Einheit in +y‑Richtung

    // Ausgabe der Komponenten beider Vektoren:
    // Erwartet:
    //   X-Komponente: 1, Y-Komponente: 0, Z-Komponente: 0
    //   X-Komponente: 0, Y-Komponente: 1, Z-Komponente: 0
    vector1.ausgabe();
    vector2.ausgabe();

    // ------------------------------------------------------------------------
    // 2. Initialisierung der Beobachter- und Sichtvektoren
    // ------------------------------------------------------------------------
    // Beobachterposition O im kartesischen Koordinatensystem:
    //   x = 0, y = R + h (radial nach außen), z = 0
    Vektor O(0.0, R + h, 0.0);

    // Start-Sichtrichtung v: tangential horizontal entlang +x
    Vektor v(1.0, 0.0, 0.0);

    // ------------------------------------------------------------------------
    // 3. Vorbereitung des Iterationsverfahrens
    // ------------------------------------------------------------------------
    const double delta = 1e-8;  // Drehschritt in Radiant (sehr klein)
    int steps = 0;               // Zähler für die Anzahl der Drehschritte

    // Vorab-Berechnung von |O|², da O konstant bleibt:
    //   |O|² = (R + h)²
    double OO = O.laenge() * O.laenge();

    // Initiales Skalarprodukt O·v (bei v horizontal): (R+h)*0 = 0
    double Ov = O.skalarProd(v);

    // Diskriminante D für die Gleichung |O + t v|² = R²:
    //   D = (O·v)² - (|O|² - R²)
    // Wenn D < 0, schneidet der Strahl die Kugel nicht (liegt oberhalb).
    // Wir rotieren, bis D >= 0 (Tangentialberührung).
    double D = Ov * Ov - (OO - R * R);

    // ------------------------------------------------------------------------
    // 4. Iterative Rotation um die z-Achse
    // ------------------------------------------------------------------------
    // Solange D < 0: Strahl trifft die Kugel nicht, daher weiter nach unten drehen
    while (D < 0.0) {
        // 4.1 Drehe den Richtungsvektor v um -delta um die z-Achse
        v.rotiereUmZ(-delta);
        ++steps;

        // 4.2 Berechne neues Skalarprodukt O·v
        Ov = O.skalarProd(v);

        // 4.3 Aktualisiere die Diskriminante D
        D = Ov * Ov - (OO - R * R);
    }
    // Wenn wir hier ankommen, ist D >= 0: erster Tangentialfall erreicht

    // ------------------------------------------------------------------------
    // 5. Auswertung: Winkel und Sichtweite
    // ------------------------------------------------------------------------
    // Winkel β in Radiant = Anzahl Schritte * delta
    double beta_rad = steps * delta;
    // Umrechnung in Grad
    double beta_deg = beta_rad * 180.0 / M_PI;

    // Berechnung der Distanz t bis zum Tangentialpunkt:
    // Aus der quadratischen Lösung bei D=0 folgt t = - (O·v)
    double S_m  = -Ov;          // Distanz in Metern
    double S_km = S_m / 1000.0; // Distanz in Kilometern

    // ------------------------------------------------------------------------
    // 6. Formatierte Ausgabe der Ergebnisse
    // ------------------------------------------------------------------------
    std::cout << std::fixed << std::setprecision(4);

    // Sichtweite in km
    std::cout << "Sie können " << S_km << " Km weit sehen." << std::endl;
    // Höhe der Plattform in m
    std::cout << "Sie sind "     << h    << " Meter hoch." << std::endl;
    // Winkel β in Grad
    std::cout << "Der Winkel beträgt " << beta_deg << " Grad." << std::endl;
    // Anzahl der benötigten Rotationsschritte
    std::cout << "Anzahl Schritte: "     << steps   << std::endl;

    return 0;
}

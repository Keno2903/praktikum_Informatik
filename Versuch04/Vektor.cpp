//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 
// 
// Versuch 04: Einführung Klasse
//
// Datei:  Vektor.cpp
// Inhalt: Sourcedatei der Klasse Vektor
//////////////////////////////////////////////////////////////////////////////

#include "Vektor.h"
/**
 * @brief Konstruktor: Initialisiert die Komponenten.
 * @param inX X‑Komponente
 * @param inY Y‑Komponente
 * @param inZ Z‑Komponente
 */
Vektor::Vektor(double inX, double inY, double inZ)
    : x(inX), y(inY), z(inZ)
{ }

/**
 * @brief Destruktor (leer).
 */
Vektor::~Vektor()
{ }

/**
 * @brief Subtrahiert einen Vektor von diesem.
 * @param input Der zu subtrahierende Vektor.
 * @return Ergebnisvektor (this - input).
 */
Vektor Vektor::sub(const Vektor& input) const
{
    return Vektor(
        x - input.x,
        y - input.y,
        z - input.z
    );
}

/**
 * @brief Berechnet die Länge (Norm) des Vektors.
 * @return Die euklidische Norm |v|.
 */
double Vektor::laenge() const
{
    return std::sqrt(x * x + y * y + z * z);
}

/**
 * @brief Berechnet das Skalarprodukt mit einem anderen Vektor.
 * @param input Der andere Vektor.
 * @return Skalarprodukt (this · input).
 */
double Vektor::skalarProd(const Vektor& input) const
{
    return x * input.x + y * input.y + z * input.z;
}

/**
 * @brief Gibt die Komponenten des Vektors auf der Konsole aus.
 */
void Vektor::ausgabe() const
{
    std::cout << "X-Komponente: " << x << std::endl;
    std::cout << "Y-Komponente: " << y << std::endl;
    std::cout << "Z-Komponente: " << z << std::endl << std::endl;
}

/**
 * @brief Berechnet den Winkel zwischen diesem und einem anderen Vektor.
 * @param input Der andere Vektor.
 * @return Winkel in Grad.
 */
double Vektor::winkel(const Vektor& input) const
{
    double skalarprod    = skalarProd(input);              // Skalarprodukt O·v
    double laenge1    = laenge();                       // Länge dieses Vektors
    double laenge2    = input.laenge();                 // Länge des anderen Vektors
    double value = std::acos(skalarprod / (laenge1 * laenge2));      // Winkel in Radiant
    return value * 180.0 / M_PI;                   // Umrechnung in Grad
}

/**
 * @brief Rotiert den Vektor um die Z‑Achse.
 * @param rad Drehwinkel in Radiant (positiv gegen den Uhrzeigersinn).
 */
void Vektor::rotiereUmZ(const double rad)
{
    // Zwischenspeicherung der alten Komponenten, damit die Matrixmultiplikation
    // mit den ursprünglichen Werten erfolgt:
    double xAlt = x;
    double yAlt = y;

    // Anwendung der Rotationsmatrix um Z:
    x = std::cos(rad) * xAlt - std::sin(rad) * yAlt;
    y = std::sin(rad) * xAlt + std::cos(rad) * yAlt;
    // z‑Komponente bleibt unverändert
}

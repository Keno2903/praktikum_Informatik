//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 
// 
// Versuch 04: Einführung Klasse
//
// Datei:  Vektor.h
// Inhalt: Headerdatei der Klasse Vektor
//////////////////////////////////////////////////////////////////////////////

#ifndef Vektor_H
#define Vektor_H

#include <iostream>
#include <cmath>
#include <iomanip>

/**
 * @class Vektor
 * @brief Repräsentiert einen 3-dimensionalen Vektor und bietet
 *        grundlegende Vektoroperationen.
 */
class Vektor
{
public:
    /**
     * @brief Konstruktor: Initialisiert die Komponenten.
     * @param x_ X‑Komponente
     * @param y_ Y‑Komponente
     * @param z_ Z‑Komponente
     */
    Vektor(double x_, double y_, double z_);

    /**
     * @brief Destruktor (leer).
     */
    ~Vektor();

    /**
     * @brief Gibt die Komponenten des Vektors auf der Konsole aus.
     */
    void ausgabe() const;

    /**
     * @brief Subtrahiert einen Vektor von diesem.
     * @param input Der zu subtrahierende Vektor.
     * @return Ergebnisvektor (this - input).
     */
    Vektor sub(const Vektor& input) const;

    /**
     * @brief Berechnet die Länge (Norm) des Vektors.
     * @return Die euklidische Norm |v|.
     */
    double laenge() const;

    /**
     * @brief Berechnet das Skalarprodukt mit einem anderen Vektor.
     * @param input Der andere Vektor.
     * @return Skalarprodukt (this · input).
     */
    double skalarProd(const Vektor& input) const;

    /**
     * @brief Berechnet den Winkel zwischen diesem und einem anderen Vektor.
     * @param input Der andere Vektor.
     * @return Winkel in Grad.
     */
    double winkel(const Vektor& input) const;

    /**
     * @brief Rotiert den Vektor um die Z‑Achse.
     * @param rad Drehwinkel in Radiant (positiv gegen den Uhrzeigersinn).
     */
    void rotiereUmZ(const double rad);

private:
    double x; /**< X‑Komponente */
    double y; /**< Y‑Komponente */
    double z; /**< Z‑Komponente */
};

#endif // Vektor_H

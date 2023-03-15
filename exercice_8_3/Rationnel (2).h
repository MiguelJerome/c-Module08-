// Déclaration de la classe Rationnel

#ifndef RATIONNEL_H
#define RATIONNEL_H

#include <iostream>

using std::istream;
using std::ostream;

// Classe représentant une fraction.
class Rationnel {
	// Surcharge des opérateurs de flux
	friend istream& operator>>( istream&, Rationnel& );					// flux d'entrées
	friend ostream& operator<<( ostream&, const Rationnel& );			// flux de sorties

	// Surcharge des opérateurs arithmétiques
	friend const Rationnel operator+( const int, const Rationnel& );	// int + Rationnel

	// Surcharge des opérateurs relationnels
	friend bool operator==( const int, const Rationnel& );				// int == Rationnel
	friend bool operator!=( const int, const Rationnel& );				// int != Rationnel

public:
	Rationnel( int = 1, int = 1 );										// constructeur par défaut

	// Surcharge des opérateurs de flux
	const Rationnel operator+( const Rationnel& ) const;				// Rationnel + Rationnel
	const Rationnel operator+( const int ) const;						// Rationnel + int

	// Surcharge des opérateurs d'affectation
	const Rationnel& operator=( const Rationnel & );					// Rationnel = Rationnel
	const Rationnel& operator=( const int );							// Rationnel = int
	const Rationnel& operator+=( const Rationnel & );					// Rationnel += Rationnel
	const Rationnel& operator+=( const int );							// Rationnel += int

	// Surcharge des opérateurs relationnels
	bool operator==( const Rationnel & ) const;							// Rationnel == Rationnel
	bool operator==( const int ) const;									// Rationnel == int
	bool operator!=( const Rationnel & ) const;							// Rationnel != Rationnel
	bool operator!=( const int ) const;									// Rationnel != int

private:
	bool reduire();														// réduit la fraction au dénominateur le plus petit

	// Fonctions arithmétiques auxiliaires
	void additionner( const Rationnel & r );
	void soustraire( const Rationnel & r );
	void multiplier( const Rationnel & r );
	void diviser( const Rationnel & r );

	double flottant() const;											// retourne le flottant correspondant

	int numerateur,														// numérateur de la fraction
		denominateur;													// dénominateur de la fraction
}; // Rationnel


#endif

// D�claration de la classe Rationnel

#ifndef RATIONNEL_H
#define RATIONNEL_H

#include <iostream>

using std::istream;
using std::ostream;

// Classe repr�sentant une fraction.
class Rationnel {
	// Surcharge des op�rateurs de flux
	friend istream& operator>>( istream&, Rationnel& );					// flux d'entr�es
	friend ostream& operator<<( ostream&, const Rationnel& );			// flux de sorties

	// Surcharge des op�rateurs arithm�tiques
	friend const Rationnel operator+( const int, const Rationnel& );	// int + Rationnel

	// Surcharge des op�rateurs relationnels
	friend bool operator==( const int, const Rationnel& );				// int == Rationnel
	friend bool operator!=( const int, const Rationnel& );				// int != Rationnel

public:
	Rationnel( int = 1, int = 1 );										// constructeur par d�faut

	// Surcharge des op�rateurs de flux
	const Rationnel operator+( const Rationnel& ) const;				// Rationnel + Rationnel
	const Rationnel operator+( const int ) const;						// Rationnel + int

	// Surcharge des op�rateurs d'affectation
	const Rationnel& operator=( const Rationnel & );					// Rationnel = Rationnel
	const Rationnel& operator=( const int );							// Rationnel = int
	const Rationnel& operator+=( const Rationnel & );					// Rationnel += Rationnel
	const Rationnel& operator+=( const int );							// Rationnel += int

	// Surcharge des op�rateurs relationnels
	bool operator==( const Rationnel & ) const;							// Rationnel == Rationnel
	bool operator==( const int ) const;									// Rationnel == int
	bool operator!=( const Rationnel & ) const;							// Rationnel != Rationnel
	bool operator!=( const int ) const;									// Rationnel != int

private:
	bool reduire();														// r�duit la fraction au d�nominateur le plus petit

	// Fonctions arithm�tiques auxiliaires
	void additionner( const Rationnel & r );
	void soustraire( const Rationnel & r );
	void multiplier( const Rationnel & r );
	void diviser( const Rationnel & r );

	double flottant() const;											// retourne le flottant correspondant

	int numerateur,														// num�rateur de la fraction
		denominateur;													// d�nominateur de la fraction
}; // Rationnel


#endif

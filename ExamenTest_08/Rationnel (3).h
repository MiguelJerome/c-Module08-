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
	// 5 + R1
	friend const Rationnel operator+( const int, const Rationnel& );	// int + Rationnel
	
	// 5 - R1 
	friend const Rationnel operator-( const int, const Rationnel& );	// int - Rationnel

	// 5 * R1
	friend const Rationnel operator*( const int, const Rationnel& );	// int * Rationnel

	// 5 / R1
	friend const Rationnel operator/( const int, const Rationnel& );	// int / Rationnel

	// Surcharge des op�rateurs relationnels
	friend bool operator==( const int, const Rationnel& );				// int == Rationnel
	friend bool operator!=( const int, const Rationnel& );				// int != Rationnel
	friend bool operator<=( const int, const Rationnel& );				// int <= Rationnel
	friend bool operator<( const int, const Rationnel& );				// int < Rationnel
	friend bool operator>=( const int, const Rationnel& );				// int >= Rationnel
	friend bool operator>( const int, const Rationnel& );				// int > Rationnel

public:
	Rationnel( int = 1, int = 1 );										// constructeur par d�faut

	// Surcharge des op�rateurs de flux
	// R1 + R2 
	const Rationnel operator+( const Rationnel& ) const;				// Rationnel + Rationnel
	// R1 + 5
	const Rationnel operator+( const int ) const;						// Rationnel + int
	
	// R1 - R2
	const Rationnel operator-( const Rationnel& ) const;				// Rationnel - Rationnel
	// R1 - 5
	const Rationnel operator-( const int ) const;						// Rationnel - int
	
	// R1 * R2
	const Rationnel operator*( const Rationnel& ) const;				// Rationnel * Rationnel
	// 5 * R1
	const Rationnel operator*( const int ) const;						// Rationnel * int
	
	const Rationnel operator/( const Rationnel& ) const;				// Rationnel / Rationnel
	const Rationnel operator/( const int ) const;						// Rationnel / int

	// Surcharge des op�rateurs d'affectation
	// R1 = R2
	const Rationnel& operator=( const Rationnel & );					// Rationnel = Rationnel
	// R1 = 5 
	const Rationnel& operator=( const int );							// Rationnel = int
	// 	R1 = R1 + R2
	const Rationnel& operator+=( const Rationnel & );					// Rationnel += Rationnel
	// R1 = R1 + 5
	const Rationnel& operator+=( const int );							// Rationnel += int
	
	const Rationnel& operator-=( const Rationnel & );					// Rationnel += Rationnel
	const Rationnel& operator-=( const int );							// Rationnel += int
	const Rationnel& operator*=( const Rationnel & );					// Rationnel += Rationnel
	const Rationnel& operator*=( const int );							// Rationnel += int
	const Rationnel& operator/=( const Rationnel & );					// Rationnel += Rationnel
	const Rationnel& operator/=( const int );							// Rationnel += int

	// Surcharge des op�rateurs relationnels
	bool operator==( const Rationnel & ) const;							// Rationnel == Rationnel
	bool operator==( const int ) const;									// Rationnel == int
	bool operator!=( const Rationnel & ) const;							// Rationnel != Rationnel
	bool operator!=( const int ) const;									// Rationnel != int
	bool operator<=( const Rationnel & ) const;							// Rationnel <= Rationnel
	bool operator<=( const int ) const;									// Rationnel <= int
	bool operator<( const Rationnel & ) const;							// Rationnel < Rationnel
	bool operator<( const int ) const;									// Rationnel < int
	bool operator>=( const Rationnel & ) const;							// Rationnel >= Rationnel
	bool operator>=( const int ) const;									// Rationnel >= int
	bool operator>( const Rationnel & ) const;							// Rationnel > Rationnel
	bool operator>( const int ) const;									// Rationnel > int

	// Surcharge des op�rateurs d'incr�mentation et d�cr�mentation
	Rationnel & operator++();											// ++ pr�-incr�mentation
	Rationnel operator++( int );										// ++ post-incr�mentation
	Rationnel & operator--();											// -- pr�-d�cr�mentation
	Rationnel operator--( int );										// -- post-d�cr�mentation

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
};


#endif

// Définitions des fonctions membres de la classe Rationnel

#include <cmath>

#include "Rationnel.h"

// Constructeur par défaut: la fraction initialisée est réduite
// si possible
// Paramètres :
//   n : valeur pour le numérateur (1 par défaut)
//   d : valeur pour le dénominateur (1 par défaut)
Rationnel::Rationnel( int n, int d ) {
	// Initialiser les attributs membres
	numerateur   = n;
	denominateur = d;

	// Réduire la fraction
	reduire();
}

// Fonction de réduction : Le plus grand commun diviseur du numérateur et du dénominateur
// est calculé, puis utilisé pour réduire la fraction.
// Valeur de retour : true si la fraction fut réduite; false sinon
bool Rationnel::reduire() {
	// Peut-on réduire?
	if ( numerateur == 0 || denominateur == 0 )
		return false;

	// Trouver le plus grand commun diviseur
	int num = abs( numerateur );
	int den = abs( denominateur );

	do {
		int reste    = num % den;
		int quotient = (num - reste) / den;
		
		if( reste == 0 ) 
			break;

		num = den;
		den = reste;
	} while ( true );

	// den est le plus grand commun disiseur, alors on peut réduire
	numerateur   /= den;
	denominateur /= den;

	// S'assurer que c'est le numérateur qui transporte le signe
	if (numerateur * denominateur < 0 )
		numerateur = -1 * abs( numerateur );
	denominateur = abs( denominateur );

	return true;
}

// Fonction d'addition : additionne la fraction donnée en paramètre à l'instance
// Paramètres:
//   r : fraction à additionner à l'instance
void Rationnel::additionner( const Rationnel & r ) {
	// Élever les deux fractions au dénominateur commun pour faire l'addition
	numerateur    = numerateur * r.denominateur + denominateur * r.numerateur;
	denominateur *= r.denominateur;

	// Réduire la fraction résultante
	reduire();
}

// Fonction de soustraction : soustrait la fraction donnée en paramètre à l'instance
// Paramètres:
//   r : fraction à soustraire à l'instance
void Rationnel::soustraire( const Rationnel & r ) {
	// Élever les deux fractions au dénominateur commun pour faire la soustraction
	numerateur    = numerateur * r.denominateur - denominateur * r.numerateur;
	denominateur *= r.denominateur;

	// Réduire la fraction résultante
	reduire();
}

// Fonction de multiplication : multiplier l'instance par la fraction donnée en paramètre 
// Paramètres:
//   r : fraction dont l'instance doit être divisée
void Rationnel::multiplier( const Rationnel & r ) {
	// Effectuer la multiplication de l'inverse de r
	numerateur   *= r.numerateur;
	denominateur *= r.denominateur;

	// Réduire la fraction résultante
	reduire();
}

// Fonction de division : diviser la fraction donnée en paramètre à l'instance
// Paramètres:
//   r : fraction à multiplier à l'instance
void Rationnel::diviser( const Rationnel & r ) {
	// Multiplication un à un
	numerateur   *= r.denominateur;
	denominateur *= r.numerateur;

	// Réduire la fraction résultante
	reduire();
}

// Fonction retournant la valeur flottante correspondant à la fraction
// Paramètres: aucun
// Valeur de retour: flottant correspondant à this
double Rationnel::flottant() const {
	return ( 1.0 * numerateur / denominateur );
}

// Surcharge de l'opérateur d'addition pour Rationnel : Rationnel + Rationnel
// Paramètre:
//   droite: instance à additionner avec this
// Valeur de retour: instance de Rationnel résultante
// R1 + R2
const Rationnel Rationnel::operator+( const Rationnel& droite ) const {
	// Créer une nouvelle instance pour héberger le résultat
	Rationnel resultat( this->numerateur, this->denominateur );

	// Effectuer l'addition (la réduction est effectuée par la fonction auxiliaire)
	resultat.additionner( droite );

	return resultat;
}

// Surcharge de l'opérateur d'addition pour Rationnel : Rationnel + int
// Paramètre:
//   droite: entier à additionner avec this
// Valeur de retour: instance de Rationnel résultante
const Rationnel Rationnel::operator+( const int droite ) const {
	// Créer une nouvelle instance initialisée à droite convertie en fraction
	Rationnel resultat( droite );

	// Invoquer Rationnel::operator+( Rationnel )
	return *this + resultat; // R1 + R2
}

// Surcharge de l'opérateur de soustraction pour Rationnel : Rationnel - Rationnel
// Paramètre:
//   droite: instance à soustraire avec this
// Valeur de retour: instance de Rationnel résultante
const Rationnel Rationnel::operator-( const Rationnel& droite ) const {
	// Créer une nouvelle instance pour héberger le résultat
	Rationnel resultat( this->numerateur, this->denominateur );

	// Effectuer la soustraction (la réduction est effectuée par la fonction auxiliaire)
	resultat.soustraire( droite );

	return resultat;
}

// Surcharge de l'opérateur de soustraction pour Rationnel : Rationnel - int
// Paramètre:
//   droite: entier à soustraire avec this
// Valeur de retour: instance de Rationnel résultante
const Rationnel Rationnel::operator-( const int droite ) const {
	// Créer une nouvelle instance initialisée à droite convertie en fraction
	Rationnel resultat( droite );

	// Invoquer Rationnel::operator-( Rationnel )
	return *this - resultat;
}

// Surcharge de l'opérateur de multiplication pour Rationnel : Rationnel * Rationnel
// Paramètre:
//   droite: instance à multiplier avec this
// Valeur de retour: instance de Rationnel résultante
const Rationnel Rationnel::operator*( const Rationnel& droite ) const {
	// Créer une nouvelle instance pour héberger le résultat
	Rationnel resultat( this->numerateur, this->denominateur );

	// Effectuer la multiplication (la réduction est effectuée par la fonction auxiliaire)
	resultat.multiplier( droite );

	return resultat;
}

// Surcharge de l'opérateur de multiplication pour Rationnel : Rationnel * int
// Paramètre:
//   droite: entier à multiplier avec this
// Valeur de retour: instance de Rationnel résultante
const Rationnel Rationnel::operator*( const int droite ) const {
	// Créer une nouvelle instance initialisée à droite convertie en fraction
	Rationnel resultat( droite );

	// Invoquer Rationnel::operator*( Rationnel )
	return *this * resultat;
}

// Surcharge de l'opérateur de division pour Rationnel : Rationnel / Rationnel
// Paramètre:
//   droite: instance à diviser à this
// Valeur de retour: instance de Rationnel résultante
const Rationnel Rationnel::operator/( const Rationnel& droite ) const {
	// Créer une nouvelle instance pour héberger le résultat
	Rationnel resultat( this->numerateur, this->denominateur );

	// Effectuer la division (la réduction est effectuée par la fonction auxiliaire)
	resultat.diviser( droite );

	return resultat;
}

// Surcharge de l'opérateur de division pour Rationnel : Rationnel / int
// Paramètre:
//   droite: entier à diviser à this
// Valeur de retour: instance de Rationnel résultante
const Rationnel Rationnel::operator/( const int droite ) const {
	// Créer une nouvelle instance initialisée à droite convertie en fraction
	Rationnel resultat( droite );

	// Invoquer Rationnel::operator/( Rationnel )
	return *this / resultat;
}

// Surcharge de l'opérateur d'affectation = pour Rationnel : Rationnel = Rationnel
// Paramètre:
//   droite: Rationnel à affecter à this
// Valeur de retour: droite affecté à this
const Rationnel& Rationnel::operator=( const Rationnel &droite ) {
	// Affectatioin par attribut
	this->numerateur   = droite.numerateur;
	this->denominateur = droite.denominateur;

	return *this;
}

// Surcharge de l'opérateur d'affectation = pour Rationnel : Rationnel = int
// Paramètre:
//   droite: entier à affecter à this
// Valeur de retour: droite affecté à this
const Rationnel& Rationnel::operator=( const int droite ) {
	// Invoque Rationnel::operator=( Rationnel )
	*this = Rationnel( droite );
	return *this;
}

// Surcharge de l'opérateur d'affectation += pour Rationnel : Rationnel += Rationnel
// Paramètre:
//   droite: Rationnel à additionner à this
// Valeur de retour: this augmenté de droite
const Rationnel& Rationnel::operator+=( const Rationnel &droite ) {
	// Invoque Rationnel::operator+( Rationnel ) et operator=( Rationnel )
	*this = *this + droite;
	return *this;
}

// Surcharge de l'opérateur d'affectation += pour Rationnel : Rationnel += int
// Paramètre:
//   droite: entier à additionner à this
// Valeur de retour: this augmenté de droite
const Rationnel& Rationnel::operator+=( const int droite ) {
	// Invoque Rationnel::operator+( Rationnel ) et operator=( Rationnel )
	*this = *this + droite;
	return *this;
}

// Surcharge de l'opérateur d'affectation -= pour Rationnel : Rationnel -= Rationnel
// Paramètre:
//   droite: Rationnel à soustraire à this
// Valeur de retour: this diminuée de droite
const Rationnel& Rationnel::operator-=( const Rationnel &droite ) {
	// Invoque Rationnel::operator-( Rationnel ) et operator=( Rationnel )
	*this = *this - droite;
	return *this;
}

// Surcharge de l'opérateur d'affectation -= pour Rationnel : Rationnel -= int
// Paramètre:
//   droite: entier à soustraire à this
// Valeur de retour: this diminuée de droite
const Rationnel& Rationnel::operator-=( const int droite ) {
	// Invoque Rationnel::operator+( Rationnel ) et operator=( Rationnel )
	*this = *this - droite;
	return *this;
}

// Surcharge de l'opérateur d'affectation *= pour Rationnel : Rationnel *= Rationnel
// Paramètre:
//   droite: Rationnel à multiplier à this
// Valeur de retour: this multipliée par droite
const Rationnel& Rationnel::operator*=( const Rationnel &droite ) {
	// Invoque Rationnel::operator*( Rationnel ) et operator=( Rationnel )
	*this = *this * droite;
	return *this;
}

// Surcharge de l'opérateur d'affectation *= pour Rationnel : Rationnel *= int
// Paramètre:
//   droite: entier à multiplier à this
// Valeur de retour: this multipliée à droite
const Rationnel& Rationnel::operator*=( const int droite ) {
	// Invoque Rationnel::operator*( Rationnel ) et operator=( Rationnel )
	*this = *this * droite;
	return *this;
}

// Surcharge de l'opérateur d'affectation /= pour Rationnel : Rationnel /= Rationnel
// Paramètre:
//   droite: Rationnel à diviser à this
// Valeur de retour: this divisé par droite
const Rationnel& Rationnel::operator/=( const Rationnel &droite ) {
	// Invoque Rationnel::operator/( Rationnel ) et operator=( Rationnel )
	*this = *this / droite;
	return *this;
}

// Surcharge de l'opérateur d'affectation /= pour Rationnel : Rationnel /= int
// Paramètre:
//   droite: entier à diviser à this
// Valeur de retour: this diviser à droite
const Rationnel& Rationnel::operator/=( const int droite ) {
	// Invoque Rationnel::operator/( Rationnel ) et operator=( Rationnel )
	*this = *this / droite;
	return *this;
}

// Surcharge de l'opérateur relationnel == pour Rationnel : Rationnel == Rationnel
// Paramètre:
//   droite: Rationnel à comparer à this
// Valeur de retour: this == droite?
bool Rationnel::operator==( const Rationnel &droite ) const {
	// Convertir en flottants et comparer les résultats
	double valGauche = this->numerateur  * 1.0 / this->denominateur;
	double valDroite = droite.numerateur * 1.0 / droite.denominateur;

	return ( valGauche == valDroite );
}

// Surcharge de l'opérateur relationnel == pour Rationnel : Rationnel == int
// Paramètre:
//   droite: entier à comparer à this
// Valeur de retour: this == droite?
bool Rationnel::operator==( const int droite ) const { 
	// Invoquer Rationnel::operator==( Rationnel )
	return ( *this == Rationnel( droite ) );
}

// Surcharge de l'opérateur relationnel != pour Rationnel : Rationnel != Rationnel
// Paramètre:
//   droite: Rationnel à comparer à this
// Valeur de retour: this != droite?
bool Rationnel::operator!=( const Rationnel &droite ) const {
	// Invoquer Rationnel::operator==( Rationnel )
	return !( *this == droite );
}

// Surcharge de l'opérateur relationnel != pour Rationnel : Rationnel != int
// Paramètre:
//   droite: entier à comparer à this
// Valeur de retour: this != droite?
bool Rationnel::operator!=( const int droite ) const { 
	// Invoquer Rationnel::operator==( int )
	return !( *this == droite );
}

// Surcharge de l'opérateur relationnel <= pour Rationnel : Rationnel <= Rationnel
// Paramètre:
//   droite: Rationnel à comparer à this
// Valeur de retour: this <= droite?
bool Rationnel::operator<=( const Rationnel &droite ) const {
	// Comparer les flottants
	return ( this->flottant() <= droite.flottant() );
}

// Surcharge de l'opérateur relationnel <= pour Rationnel : Rationnel <= int
// Paramètre:
//   droite: entier à comparer à this
// Valeur de retour: this <= droite?
bool Rationnel::operator<=( const int droite ) const { 
	// Invoquer Rationnel::operator<=( Rationnel )
	return *this <= Rationnel( droite );
}

// Surcharge de l'opérateur relationnel < pour Rationnel : Rationnel < Rationnel
// Paramètre:
//   droite: Rationnel à comparer à this
// Valeur de retour: this < droite?
bool Rationnel::operator<( const Rationnel &droite ) const {
	// Comparer les flottants
	return ( this->flottant() < droite.flottant() );
}

// Surcharge de l'opérateur relationnel < pour Rationnel : Rationnel < int
// Paramètre:
//   droite: entier à comparer à this
// Valeur de retour: this < droite?
bool Rationnel::operator<( const int droite ) const { 
	// Invoquer Rationnel::operator<( Rationnel )
	return *this < Rationnel( droite );
}

// Surcharge de l'opérateur relationnel >= pour Rationnel : Rationnel >= Rationnel
// Paramètre:
//   droite: Rationnel à comparer à this
// Valeur de retour: this >= droite?
bool Rationnel::operator>=( const Rationnel &droite ) const {
	// Comparer les flottants
	return ( this->flottant() >= droite.flottant() );
}

// Surcharge de l'opérateur relationnel >= pour Rationnel : Rationnel >= int
// Paramètre:
//   droite: entier à comparer à this
// Valeur de retour: this >= droite?
bool Rationnel::operator>=( const int droite ) const { 
	// Invoquer Rationnel::operator>=( Rationnel )
	return *this >= Rationnel( droite );
}

// Surcharge de l'opérateur relationnel > pour Rationnel : Rationnel > Rationnel
// Paramètre:
//   droite: Rationnel à comparer à this
// Valeur de retour: this > droite?
bool Rationnel::operator>( const Rationnel &droite ) const {
	// Comparer les flottants
	return ( this->flottant() > droite.flottant() );
}

// Surcharge de l'opérateur relationnel > pour Rationnel : Rationnel > int
// Paramètre:
//   droite: entier à comparer à this
// Valeur de retour: this > droite?
bool Rationnel::operator>( const int droite ) const { 
	// Invoquer Rationnel::operator>( Rationnel )
	return *this > Rationnel( droite );
}

// Surcharge de l'opérateur pré-incrémentation pour Rationnel : ++Rationnel
// Paramètre: aucun
// Valeur de retour: this après incrémentation
Rationnel & Rationnel::operator++() {
	// Invoquer Rationnel::operator+( int )
	*this = *this + 1;
	return *this;
}

// Surcharge de l'opérateur post-incrémentation pour Rationnel : Rationnel++
// Paramètre: aucun
// Valeur de retour: this avant incrémentation
Rationnel Rationnel::operator++( int ) {
	// Invoquer Rationnel::operator=( Rationnel )
	Rationnel temp = *this;

	// Invoquer Rationnel::operator+( int )
	*this = *this + 1;

	return temp;
}

// Surcharge de l'opérateur pré-décrémentation pour Rationnel : --Rationnel
// Paramètre: aucun
// Valeur de retour: this après décrémentation
Rationnel & Rationnel::operator--() {
	// Invoquer Rationnel::operator-( int )
	*this = *this - 1;
	return *this;
}

// Surcharge de l'opérateur post-décrémentation pour Rationnel : Rationnel--
// Paramètre: aucun
// Valeur de retour: this avant décrémentation
Rationnel Rationnel::operator--( int ) {
	// Invoquer Rationnel::operator=( Rationnel )
	Rationnel temp = *this;

	// Invoquer Rationnel::operator-( int )
	*this = *this - 1;

	return temp;
}

// Surcharge de l'opérateur de flux d'entrées pour Rationnel
// Paramètres:
//   istr: flux d'entrées à exploiter
//   r   : instance dans laquelle lire
istream& operator>>( istream& istr, Rationnel& r ) {
	char sep;
	istr >> r.numerateur >> sep >> r.denominateur;
	r.reduire();

	return istr;
}

// Surcharge de l'opérateur de flux de sorties pour Rationnel
// Paramètres:
//   istr: flux de sorties à exploiter
//   r   : instance à afficher
ostream& operator<<( ostream& ostr, const Rationnel& r ) {
	ostr << r.numerateur << '/' << r.denominateur;
	return ostr;
}

// Surcharge de l'opérateur d'addition pour Rationnel : int + Rationnel
// Paramètre:
//   gauche: entier à additionner
//   droite: Rationnel à additionner
// Valeur de retour: instance de Rationnel résultante
// 5 + R1
const Rationnel operator+( const int gauche, const Rationnel& droite ) {
	// Invoquer Rationnel::operator+( Rationnel )
	return Rationnel( gauche ) + droite;
}

// Surcharge de l'opérateur de soustraction pour Rationnel : int - Rationnel
// Paramètre:
//   gauche: entier à soustraire
//   droite: Rationnel à soustraire
// Valeur de retour: instance de Rationnel résultante
const Rationnel operator-( const int gauche, const Rationnel& droite ) {
	// Invoquer Rationnel::operator-( Rationnel )
	return Rationnel( gauche ) - droite;
}

// Surcharge de l'opérateur de multiplication pour Rationnel : int * Rationnel
// Paramètre:
//   gauche: entier à multiplier
//   droite: Rationnel à multiplier
// Valeur de retour: instance de Rationnel résultante
const Rationnel operator*( const int gauche, const Rationnel& droite ) {
	// Invoquer Rationnel::operator*( Rationnel )
	return Rationnel( gauche ) * droite;
}

// Surcharge de l'opérateur de division pour Rationnel : int / Rationnel
// Paramètre:
//   gauche: entier divisé
//   droite: Rationnel diviseur
// Valeur de retour: instance de Rationnel résultante
const Rationnel operator/( const int gauche, const Rationnel& droite ) {
	// Invoquer Rationnel::operator/( Rationnel )
	return Rationnel( gauche ) / droite;
}

// Surcharge de l'opérateur relationnel == pour Rationnel : int == Rationnel
// Paramètre:
//   gauche: entier à comparer à droite
//   droite: Rationnel à comparer à gauche
// Valeur de retour: this == droite?
bool operator==( const int gauche, const Rationnel& droite ) { 
	// Invoquer Rationnel::operator==( int )
	return ( droite == gauche );
}

// Surcharge de l'opérateur relationnel != pour Rationnel : int != Rationnel
// Paramètre:
//   gauche: entier à comparer à droite
//   droite: Rationnel à comparer à gauche
// Valeur de retour: this != droite?
bool operator!=( const int gauche, const Rationnel& droite ) { 
	// Invoquer Rationnel::operator==( int, Rationnel )
	return ( droite != gauche );
}

// Surcharge de l'opérateur relationnel <= pour Rationnel : int <= Rationnel
// Paramètre:
//   gauche: entier à comparer à droite
//   droite: Rationnel à comparer à gauche
// Valeur de retour: this <= droite?
bool operator<=( const int gauche, const Rationnel& droite ) { 
	// Invoquer Rationnel::operator<=( Rationnel, Rationnel )
	return ( Rationnel( gauche ) <= droite );
}

// Surcharge de l'opérateur relationnel < pour Rationnel : int < Rationnel
// Paramètre:
//   gauche: entier à comparer à droite
//   droite: Rationnel à comparer à gauche
// Valeur de retour: this < droite?
bool operator<( const int gauche, const Rationnel& droite ) { 
	// Invoquer Rationnel::operator<( Rationnel, Rationnel )
	return ( Rationnel( gauche ) < droite );
}

// Surcharge de l'opérateur relationnel >= pour Rationnel : int >= Rationnel
// Paramètre:
//   gauche: entier à comparer à droite
//   droite: Rationnel à comparer à gauche
// Valeur de retour: this >= droite?
bool operator>=( const int gauche, const Rationnel& droite ) { 
	// Invoquer Rationnel::operator>=( Rationnel, Rationnel )
	return ( Rationnel( gauche ) >= droite );
}

// Surcharge de l'opérateur relationnel > pour Rationnel : int > Rationnel
// Paramètre:
//   gauche: entier à comparer à droite
//   droite: Rationnel à comparer à gauche
// Valeur de retour: this > droite?
bool operator>( const int gauche, const Rationnel& droite ) { 
	// Invoquer Rationnel::operator<>( Rationnel, Rationnel )
	return ( Rationnel( gauche ) > droite );
}


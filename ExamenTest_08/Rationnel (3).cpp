// D�finitions des fonctions membres de la classe Rationnel

#include <cmath>

#include "Rationnel.h"

// Constructeur par d�faut: la fraction initialis�e est r�duite
// si possible
// Param�tres :
//   n : valeur pour le num�rateur (1 par d�faut)
//   d : valeur pour le d�nominateur (1 par d�faut)
Rationnel::Rationnel( int n, int d ) {
	// Initialiser les attributs membres
	numerateur   = n;
	denominateur = d;

	// R�duire la fraction
	reduire();
}

// Fonction de r�duction : Le plus grand commun diviseur du num�rateur et du d�nominateur
// est calcul�, puis utilis� pour r�duire la fraction.
// Valeur de retour : true si la fraction fut r�duite; false sinon
bool Rationnel::reduire() {
	// Peut-on r�duire?
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

	// den est le plus grand commun disiseur, alors on peut r�duire
	numerateur   /= den;
	denominateur /= den;

	// S'assurer que c'est le num�rateur qui transporte le signe
	if (numerateur * denominateur < 0 )
		numerateur = -1 * abs( numerateur );
	denominateur = abs( denominateur );

	return true;
}

// Fonction d'addition : additionne la fraction donn�e en param�tre � l'instance
// Param�tres:
//   r : fraction � additionner � l'instance
void Rationnel::additionner( const Rationnel & r ) {
	// �lever les deux fractions au d�nominateur commun pour faire l'addition
	numerateur    = numerateur * r.denominateur + denominateur * r.numerateur;
	denominateur *= r.denominateur;

	// R�duire la fraction r�sultante
	reduire();
}

// Fonction de soustraction : soustrait la fraction donn�e en param�tre � l'instance
// Param�tres:
//   r : fraction � soustraire � l'instance
void Rationnel::soustraire( const Rationnel & r ) {
	// �lever les deux fractions au d�nominateur commun pour faire la soustraction
	numerateur    = numerateur * r.denominateur - denominateur * r.numerateur;
	denominateur *= r.denominateur;

	// R�duire la fraction r�sultante
	reduire();
}

// Fonction de multiplication : multiplier l'instance par la fraction donn�e en param�tre 
// Param�tres:
//   r : fraction dont l'instance doit �tre divis�e
void Rationnel::multiplier( const Rationnel & r ) {
	// Effectuer la multiplication de l'inverse de r
	numerateur   *= r.numerateur;
	denominateur *= r.denominateur;

	// R�duire la fraction r�sultante
	reduire();
}

// Fonction de division : diviser la fraction donn�e en param�tre � l'instance
// Param�tres:
//   r : fraction � multiplier � l'instance
void Rationnel::diviser( const Rationnel & r ) {
	// Multiplication un � un
	numerateur   *= r.denominateur;
	denominateur *= r.numerateur;

	// R�duire la fraction r�sultante
	reduire();
}

// Fonction retournant la valeur flottante correspondant � la fraction
// Param�tres: aucun
// Valeur de retour: flottant correspondant � this
double Rationnel::flottant() const {
	return ( 1.0 * numerateur / denominateur );
}

// Surcharge de l'op�rateur d'addition pour Rationnel : Rationnel + Rationnel
// Param�tre:
//   droite: instance � additionner avec this
// Valeur de retour: instance de Rationnel r�sultante
// R1 + R2
const Rationnel Rationnel::operator+( const Rationnel& droite ) const {
	// Cr�er une nouvelle instance pour h�berger le r�sultat
	Rationnel resultat( this->numerateur, this->denominateur );

	// Effectuer l'addition (la r�duction est effectu�e par la fonction auxiliaire)
	resultat.additionner( droite );

	return resultat;
}

// Surcharge de l'op�rateur d'addition pour Rationnel : Rationnel + int
// Param�tre:
//   droite: entier � additionner avec this
// Valeur de retour: instance de Rationnel r�sultante
const Rationnel Rationnel::operator+( const int droite ) const {
	// Cr�er une nouvelle instance initialis�e � droite convertie en fraction
	Rationnel resultat( droite );

	// Invoquer Rationnel::operator+( Rationnel )
	return *this + resultat; // R1 + R2
}

// Surcharge de l'op�rateur de soustraction pour Rationnel : Rationnel - Rationnel
// Param�tre:
//   droite: instance � soustraire avec this
// Valeur de retour: instance de Rationnel r�sultante
const Rationnel Rationnel::operator-( const Rationnel& droite ) const {
	// Cr�er une nouvelle instance pour h�berger le r�sultat
	Rationnel resultat( this->numerateur, this->denominateur );

	// Effectuer la soustraction (la r�duction est effectu�e par la fonction auxiliaire)
	resultat.soustraire( droite );

	return resultat;
}

// Surcharge de l'op�rateur de soustraction pour Rationnel : Rationnel - int
// Param�tre:
//   droite: entier � soustraire avec this
// Valeur de retour: instance de Rationnel r�sultante
const Rationnel Rationnel::operator-( const int droite ) const {
	// Cr�er une nouvelle instance initialis�e � droite convertie en fraction
	Rationnel resultat( droite );

	// Invoquer Rationnel::operator-( Rationnel )
	return *this - resultat;
}

// Surcharge de l'op�rateur de multiplication pour Rationnel : Rationnel * Rationnel
// Param�tre:
//   droite: instance � multiplier avec this
// Valeur de retour: instance de Rationnel r�sultante
const Rationnel Rationnel::operator*( const Rationnel& droite ) const {
	// Cr�er une nouvelle instance pour h�berger le r�sultat
	Rationnel resultat( this->numerateur, this->denominateur );

	// Effectuer la multiplication (la r�duction est effectu�e par la fonction auxiliaire)
	resultat.multiplier( droite );

	return resultat;
}

// Surcharge de l'op�rateur de multiplication pour Rationnel : Rationnel * int
// Param�tre:
//   droite: entier � multiplier avec this
// Valeur de retour: instance de Rationnel r�sultante
const Rationnel Rationnel::operator*( const int droite ) const {
	// Cr�er une nouvelle instance initialis�e � droite convertie en fraction
	Rationnel resultat( droite );

	// Invoquer Rationnel::operator*( Rationnel )
	return *this * resultat;
}

// Surcharge de l'op�rateur de division pour Rationnel : Rationnel / Rationnel
// Param�tre:
//   droite: instance � diviser � this
// Valeur de retour: instance de Rationnel r�sultante
const Rationnel Rationnel::operator/( const Rationnel& droite ) const {
	// Cr�er une nouvelle instance pour h�berger le r�sultat
	Rationnel resultat( this->numerateur, this->denominateur );

	// Effectuer la division (la r�duction est effectu�e par la fonction auxiliaire)
	resultat.diviser( droite );

	return resultat;
}

// Surcharge de l'op�rateur de division pour Rationnel : Rationnel / int
// Param�tre:
//   droite: entier � diviser � this
// Valeur de retour: instance de Rationnel r�sultante
const Rationnel Rationnel::operator/( const int droite ) const {
	// Cr�er une nouvelle instance initialis�e � droite convertie en fraction
	Rationnel resultat( droite );

	// Invoquer Rationnel::operator/( Rationnel )
	return *this / resultat;
}

// Surcharge de l'op�rateur d'affectation = pour Rationnel : Rationnel = Rationnel
// Param�tre:
//   droite: Rationnel � affecter � this
// Valeur de retour: droite affect� � this
const Rationnel& Rationnel::operator=( const Rationnel &droite ) {
	// Affectatioin par attribut
	this->numerateur   = droite.numerateur;
	this->denominateur = droite.denominateur;

	return *this;
}

// Surcharge de l'op�rateur d'affectation = pour Rationnel : Rationnel = int
// Param�tre:
//   droite: entier � affecter � this
// Valeur de retour: droite affect� � this
const Rationnel& Rationnel::operator=( const int droite ) {
	// Invoque Rationnel::operator=( Rationnel )
	*this = Rationnel( droite );
	return *this;
}

// Surcharge de l'op�rateur d'affectation += pour Rationnel : Rationnel += Rationnel
// Param�tre:
//   droite: Rationnel � additionner � this
// Valeur de retour: this augment� de droite
const Rationnel& Rationnel::operator+=( const Rationnel &droite ) {
	// Invoque Rationnel::operator+( Rationnel ) et operator=( Rationnel )
	*this = *this + droite;
	return *this;
}

// Surcharge de l'op�rateur d'affectation += pour Rationnel : Rationnel += int
// Param�tre:
//   droite: entier � additionner � this
// Valeur de retour: this augment� de droite
const Rationnel& Rationnel::operator+=( const int droite ) {
	// Invoque Rationnel::operator+( Rationnel ) et operator=( Rationnel )
	*this = *this + droite;
	return *this;
}

// Surcharge de l'op�rateur d'affectation -= pour Rationnel : Rationnel -= Rationnel
// Param�tre:
//   droite: Rationnel � soustraire � this
// Valeur de retour: this diminu�e de droite
const Rationnel& Rationnel::operator-=( const Rationnel &droite ) {
	// Invoque Rationnel::operator-( Rationnel ) et operator=( Rationnel )
	*this = *this - droite;
	return *this;
}

// Surcharge de l'op�rateur d'affectation -= pour Rationnel : Rationnel -= int
// Param�tre:
//   droite: entier � soustraire � this
// Valeur de retour: this diminu�e de droite
const Rationnel& Rationnel::operator-=( const int droite ) {
	// Invoque Rationnel::operator+( Rationnel ) et operator=( Rationnel )
	*this = *this - droite;
	return *this;
}

// Surcharge de l'op�rateur d'affectation *= pour Rationnel : Rationnel *= Rationnel
// Param�tre:
//   droite: Rationnel � multiplier � this
// Valeur de retour: this multipli�e par droite
const Rationnel& Rationnel::operator*=( const Rationnel &droite ) {
	// Invoque Rationnel::operator*( Rationnel ) et operator=( Rationnel )
	*this = *this * droite;
	return *this;
}

// Surcharge de l'op�rateur d'affectation *= pour Rationnel : Rationnel *= int
// Param�tre:
//   droite: entier � multiplier � this
// Valeur de retour: this multipli�e � droite
const Rationnel& Rationnel::operator*=( const int droite ) {
	// Invoque Rationnel::operator*( Rationnel ) et operator=( Rationnel )
	*this = *this * droite;
	return *this;
}

// Surcharge de l'op�rateur d'affectation /= pour Rationnel : Rationnel /= Rationnel
// Param�tre:
//   droite: Rationnel � diviser � this
// Valeur de retour: this divis� par droite
const Rationnel& Rationnel::operator/=( const Rationnel &droite ) {
	// Invoque Rationnel::operator/( Rationnel ) et operator=( Rationnel )
	*this = *this / droite;
	return *this;
}

// Surcharge de l'op�rateur d'affectation /= pour Rationnel : Rationnel /= int
// Param�tre:
//   droite: entier � diviser � this
// Valeur de retour: this diviser � droite
const Rationnel& Rationnel::operator/=( const int droite ) {
	// Invoque Rationnel::operator/( Rationnel ) et operator=( Rationnel )
	*this = *this / droite;
	return *this;
}

// Surcharge de l'op�rateur relationnel == pour Rationnel : Rationnel == Rationnel
// Param�tre:
//   droite: Rationnel � comparer � this
// Valeur de retour: this == droite?
bool Rationnel::operator==( const Rationnel &droite ) const {
	// Convertir en flottants et comparer les r�sultats
	double valGauche = this->numerateur  * 1.0 / this->denominateur;
	double valDroite = droite.numerateur * 1.0 / droite.denominateur;

	return ( valGauche == valDroite );
}

// Surcharge de l'op�rateur relationnel == pour Rationnel : Rationnel == int
// Param�tre:
//   droite: entier � comparer � this
// Valeur de retour: this == droite?
bool Rationnel::operator==( const int droite ) const { 
	// Invoquer Rationnel::operator==( Rationnel )
	return ( *this == Rationnel( droite ) );
}

// Surcharge de l'op�rateur relationnel != pour Rationnel : Rationnel != Rationnel
// Param�tre:
//   droite: Rationnel � comparer � this
// Valeur de retour: this != droite?
bool Rationnel::operator!=( const Rationnel &droite ) const {
	// Invoquer Rationnel::operator==( Rationnel )
	return !( *this == droite );
}

// Surcharge de l'op�rateur relationnel != pour Rationnel : Rationnel != int
// Param�tre:
//   droite: entier � comparer � this
// Valeur de retour: this != droite?
bool Rationnel::operator!=( const int droite ) const { 
	// Invoquer Rationnel::operator==( int )
	return !( *this == droite );
}

// Surcharge de l'op�rateur relationnel <= pour Rationnel : Rationnel <= Rationnel
// Param�tre:
//   droite: Rationnel � comparer � this
// Valeur de retour: this <= droite?
bool Rationnel::operator<=( const Rationnel &droite ) const {
	// Comparer les flottants
	return ( this->flottant() <= droite.flottant() );
}

// Surcharge de l'op�rateur relationnel <= pour Rationnel : Rationnel <= int
// Param�tre:
//   droite: entier � comparer � this
// Valeur de retour: this <= droite?
bool Rationnel::operator<=( const int droite ) const { 
	// Invoquer Rationnel::operator<=( Rationnel )
	return *this <= Rationnel( droite );
}

// Surcharge de l'op�rateur relationnel < pour Rationnel : Rationnel < Rationnel
// Param�tre:
//   droite: Rationnel � comparer � this
// Valeur de retour: this < droite?
bool Rationnel::operator<( const Rationnel &droite ) const {
	// Comparer les flottants
	return ( this->flottant() < droite.flottant() );
}

// Surcharge de l'op�rateur relationnel < pour Rationnel : Rationnel < int
// Param�tre:
//   droite: entier � comparer � this
// Valeur de retour: this < droite?
bool Rationnel::operator<( const int droite ) const { 
	// Invoquer Rationnel::operator<( Rationnel )
	return *this < Rationnel( droite );
}

// Surcharge de l'op�rateur relationnel >= pour Rationnel : Rationnel >= Rationnel
// Param�tre:
//   droite: Rationnel � comparer � this
// Valeur de retour: this >= droite?
bool Rationnel::operator>=( const Rationnel &droite ) const {
	// Comparer les flottants
	return ( this->flottant() >= droite.flottant() );
}

// Surcharge de l'op�rateur relationnel >= pour Rationnel : Rationnel >= int
// Param�tre:
//   droite: entier � comparer � this
// Valeur de retour: this >= droite?
bool Rationnel::operator>=( const int droite ) const { 
	// Invoquer Rationnel::operator>=( Rationnel )
	return *this >= Rationnel( droite );
}

// Surcharge de l'op�rateur relationnel > pour Rationnel : Rationnel > Rationnel
// Param�tre:
//   droite: Rationnel � comparer � this
// Valeur de retour: this > droite?
bool Rationnel::operator>( const Rationnel &droite ) const {
	// Comparer les flottants
	return ( this->flottant() > droite.flottant() );
}

// Surcharge de l'op�rateur relationnel > pour Rationnel : Rationnel > int
// Param�tre:
//   droite: entier � comparer � this
// Valeur de retour: this > droite?
bool Rationnel::operator>( const int droite ) const { 
	// Invoquer Rationnel::operator>( Rationnel )
	return *this > Rationnel( droite );
}

// Surcharge de l'op�rateur pr�-incr�mentation pour Rationnel : ++Rationnel
// Param�tre: aucun
// Valeur de retour: this apr�s incr�mentation
Rationnel & Rationnel::operator++() {
	// Invoquer Rationnel::operator+( int )
	*this = *this + 1;
	return *this;
}

// Surcharge de l'op�rateur post-incr�mentation pour Rationnel : Rationnel++
// Param�tre: aucun
// Valeur de retour: this avant incr�mentation
Rationnel Rationnel::operator++( int ) {
	// Invoquer Rationnel::operator=( Rationnel )
	Rationnel temp = *this;

	// Invoquer Rationnel::operator+( int )
	*this = *this + 1;

	return temp;
}

// Surcharge de l'op�rateur pr�-d�cr�mentation pour Rationnel : --Rationnel
// Param�tre: aucun
// Valeur de retour: this apr�s d�cr�mentation
Rationnel & Rationnel::operator--() {
	// Invoquer Rationnel::operator-( int )
	*this = *this - 1;
	return *this;
}

// Surcharge de l'op�rateur post-d�cr�mentation pour Rationnel : Rationnel--
// Param�tre: aucun
// Valeur de retour: this avant d�cr�mentation
Rationnel Rationnel::operator--( int ) {
	// Invoquer Rationnel::operator=( Rationnel )
	Rationnel temp = *this;

	// Invoquer Rationnel::operator-( int )
	*this = *this - 1;

	return temp;
}

// Surcharge de l'op�rateur de flux d'entr�es pour Rationnel
// Param�tres:
//   istr: flux d'entr�es � exploiter
//   r   : instance dans laquelle lire
istream& operator>>( istream& istr, Rationnel& r ) {
	char sep;
	istr >> r.numerateur >> sep >> r.denominateur;
	r.reduire();

	return istr;
}

// Surcharge de l'op�rateur de flux de sorties pour Rationnel
// Param�tres:
//   istr: flux de sorties � exploiter
//   r   : instance � afficher
ostream& operator<<( ostream& ostr, const Rationnel& r ) {
	ostr << r.numerateur << '/' << r.denominateur;
	return ostr;
}

// Surcharge de l'op�rateur d'addition pour Rationnel : int + Rationnel
// Param�tre:
//   gauche: entier � additionner
//   droite: Rationnel � additionner
// Valeur de retour: instance de Rationnel r�sultante
// 5 + R1
const Rationnel operator+( const int gauche, const Rationnel& droite ) {
	// Invoquer Rationnel::operator+( Rationnel )
	return Rationnel( gauche ) + droite;
}

// Surcharge de l'op�rateur de soustraction pour Rationnel : int - Rationnel
// Param�tre:
//   gauche: entier � soustraire
//   droite: Rationnel � soustraire
// Valeur de retour: instance de Rationnel r�sultante
const Rationnel operator-( const int gauche, const Rationnel& droite ) {
	// Invoquer Rationnel::operator-( Rationnel )
	return Rationnel( gauche ) - droite;
}

// Surcharge de l'op�rateur de multiplication pour Rationnel : int * Rationnel
// Param�tre:
//   gauche: entier � multiplier
//   droite: Rationnel � multiplier
// Valeur de retour: instance de Rationnel r�sultante
const Rationnel operator*( const int gauche, const Rationnel& droite ) {
	// Invoquer Rationnel::operator*( Rationnel )
	return Rationnel( gauche ) * droite;
}

// Surcharge de l'op�rateur de division pour Rationnel : int / Rationnel
// Param�tre:
//   gauche: entier divis�
//   droite: Rationnel diviseur
// Valeur de retour: instance de Rationnel r�sultante
const Rationnel operator/( const int gauche, const Rationnel& droite ) {
	// Invoquer Rationnel::operator/( Rationnel )
	return Rationnel( gauche ) / droite;
}

// Surcharge de l'op�rateur relationnel == pour Rationnel : int == Rationnel
// Param�tre:
//   gauche: entier � comparer � droite
//   droite: Rationnel � comparer � gauche
// Valeur de retour: this == droite?
bool operator==( const int gauche, const Rationnel& droite ) { 
	// Invoquer Rationnel::operator==( int )
	return ( droite == gauche );
}

// Surcharge de l'op�rateur relationnel != pour Rationnel : int != Rationnel
// Param�tre:
//   gauche: entier � comparer � droite
//   droite: Rationnel � comparer � gauche
// Valeur de retour: this != droite?
bool operator!=( const int gauche, const Rationnel& droite ) { 
	// Invoquer Rationnel::operator==( int, Rationnel )
	return ( droite != gauche );
}

// Surcharge de l'op�rateur relationnel <= pour Rationnel : int <= Rationnel
// Param�tre:
//   gauche: entier � comparer � droite
//   droite: Rationnel � comparer � gauche
// Valeur de retour: this <= droite?
bool operator<=( const int gauche, const Rationnel& droite ) { 
	// Invoquer Rationnel::operator<=( Rationnel, Rationnel )
	return ( Rationnel( gauche ) <= droite );
}

// Surcharge de l'op�rateur relationnel < pour Rationnel : int < Rationnel
// Param�tre:
//   gauche: entier � comparer � droite
//   droite: Rationnel � comparer � gauche
// Valeur de retour: this < droite?
bool operator<( const int gauche, const Rationnel& droite ) { 
	// Invoquer Rationnel::operator<( Rationnel, Rationnel )
	return ( Rationnel( gauche ) < droite );
}

// Surcharge de l'op�rateur relationnel >= pour Rationnel : int >= Rationnel
// Param�tre:
//   gauche: entier � comparer � droite
//   droite: Rationnel � comparer � gauche
// Valeur de retour: this >= droite?
bool operator>=( const int gauche, const Rationnel& droite ) { 
	// Invoquer Rationnel::operator>=( Rationnel, Rationnel )
	return ( Rationnel( gauche ) >= droite );
}

// Surcharge de l'op�rateur relationnel > pour Rationnel : int > Rationnel
// Param�tre:
//   gauche: entier � comparer � droite
//   droite: Rationnel � comparer � gauche
// Valeur de retour: this > droite?
bool operator>( const int gauche, const Rationnel& droite ) { 
	// Invoquer Rationnel::operator<>( Rationnel, Rationnel )
	return ( Rationnel( gauche ) > droite );
}


// D�finitions des fonctions membres de la classe Date

#include <iostream>
#include <iomanip>
#include "date.h"

using std::cout;
using std::setw;

// Constructeur Date simple sans contr�le de l'�chelle.
Date::Date( int j, int m, int a ) {
	jour  = j;
	mois  = m;
	annee = a;

	// On s'assure que les valeurs d'attributs fournis sont valid�s
	validerAttributs();
}	// Date

// Affiche Date selon le format jj-mm-aaaa.
void Date::afficher() {
	cout.fill('0');
	cout << setw(2) << jour << '-' 
		 << setw(2) << mois << '-' 
		 << setw(4) << annee;
}	// afficher

// Valide les attributs et les corrige au besoin (en consid�rant les
// ann�es bisextiles)
void Date::validerAttributs() {
	// Valider l'ann�e
	if ( annee < 0 )
		annee = 0;

	// Valider le mois
	if ( mois < 1 )
		mois = 1;
	else if ( mois > 12 )
		mois = 12;

	// Valider le jour
	if ( jour < 1 )
		jour = 1;
	else
		// Valider le jour maximal selon le mois
		switch ( mois ) {
			case 1:			// Janvier
			case 3:			// Mars
			case 5:			// Mai
			case 7:			// Juillet
			case 8:			// Ao�t
			case 10:		// Octobre
			case 12:		// D�cembre
				if (jour > 31 )
					jour = 31;
				break;

			case 4:			// Avril
			case 6:			// Juin
			case 9:			// Septembre
			case 11:		// Novembre
				if ( jour > 30 )
					jour = 30;
				break;

			default:		// F�vrier
				// Est-ce une ann�e bisextile?
				if ( ( annee % 4 == 0 && annee % 100 != 0 ) || ( annee % 400 == 0 ) ) {
					if ( jour > 29 )
						jour = 29;
				}
				else if ( jour > 28 )
					jour = 28;
		}
}	// validerAttributs

// Incr�mente la date d'une journ�e (en consid�rant les ann�es bisextiles)
void Date::jourSuivant() {
	jour++;

	// Passer au mois suivant si besion est

	switch ( mois ) {
		case 1:			// Janvier
		case 3:			// Mars
		case 5:			// Mai
		case 7:			// Juillet
		case 8:			// Ao�t
		case 10:		// Octobre
		case 12:		// D�cembre
			if (jour > 31 ) {
				mois++;
				jour = 1;
			}
			break;

		case 4:			// Avril
		case 6:			// Juin
		case 9:			// Septembre
		case 11:		// Novembre
			if ( jour > 30 ) {
				mois++;
				jour = 1;
			}
			break;

		default:		// F�vrier
			// Est-ce une ann�e bisextile?
			if ( ( annee % 4 == 0 && annee % 100 != 0 ) || ( annee % 400 == 0 ) ) {
				if ( jour > 29 ) {
					mois++;
					jour = 1;
				}
			}
			else if ( jour > 28 ) {
				mois++;
				jour = 1;
			}
	}

	// Passer � l'ann�e suivante si besoin est
	if ( mois > 12 ) {
		annee++;
		mois = 1;
	}
}	// jourSuivant

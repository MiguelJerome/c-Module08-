/*=============================================================
Programmeur : Marco Lavoie
Fichier     : Exercice_6_2.cpp
Description : Classe Date avec incrémentation des jours.
Date        : 2010/03/01
Source      : Exercice 6.9 dans Deitel & Deitel, p. 450
              Notes de cours de 14728 ORD, Marco Lavoie, 6.43
===============================================================*/

#include "stdafx.h"		// exclusif à Visual Studio

#include <iostream>		// cin, cout et endl
#include <conio.h>		// _getch()

#include "date.h"		// déclaration de la classe Date

using std::cout;
using std::endl;

// Programme simple testant le constructeur et l'affectation par 
// copie de la classe Date.
int main() {
	Date date( 40, 0, 2008 ); // date ajuste à 31/01/2008

	// Boucle de testing d'incrémentation de date
	for ( int j = 0; j < 400; j++ ) {
		date.afficher();
		cout << endl;

		date.jourSuivant();
	}

	// Attendre confirmation pour fermer la console
	std::cout << "\nPressez une touche pour terminer..." << std::endl;
	_getch();

	return 0;
}	// _tmain


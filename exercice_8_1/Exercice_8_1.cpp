/*=============================================================
Programmeur : Marco Lavoie
Fichier     : Exercice_8_1.cpp
Description : Implantation de la classe Rationnel
Date        : 2010/02/25
Source      : Notes de cours de 20887 ORD, Marco Lavoie, 6.49
=============================================================*/

#include "stdafx.h"					// exclusif à Visual Studio

#include <iostream>					// cin, cout et endl
#include <iomanip>					// setw()
#include <conio.h>					// _getch()

#include "Rationnel.h"

// Programme principal : teste la classe Rationnel
int _tmain(int argc, _TCHAR* argv[]) {
	Rationnel r1,			// devrait être 1/1
		      r2( 2 ),		// devrait être 2/1
			  r3( 6, 9 ),	// devrait être 2/3
			  r4( 3, -5 );  // devrait être -3/5 (le signe doit toujours être attribué au numérateur)

	// Afficher les instances pour validation
	std::cout << "r1 = " << r1 << std::endl;		// devrait afficher 1/1, 1
	std::cout << "r2 = " << r2 << std::endl;		// devrait afficher 2/1, 2
	std::cout << "r3 = " << r3 << std::endl;		// devrait afficher 2/3, 0.666667
	std::cout << "r4 = " << r4 << std::endl;		// devrait afficher -3/5, -0.6

	// Tester l'addition de r2 à r4, puis afficher le résultat pour validation
	r4.additionner( r2 );
	std::cout << "\nr4 = r4 + r2 >>> r4 = " << r4 << std::endl;	// devrait afficher 7/5, 1.4

	// Tester la soustraction de r3 à r4, puis afficher le résultat pour validation
	r4.soustraire( r3 );
	std::cout << "r4 = r4 - r3 >>> r4 = " << r4 << std::endl;		// devrait afficher 11/15, 0.733333

	// Tester la division de r4 à r3, puis afficher le résultat pour validation
	r4.diviser( r3 );
	std::cout << "r4 = r4 / r3 >>> r4 = " << r4 << std::endl;		// devrait afficher 11/10, 1.1

	// Tester la multiplication de r2 à r4, puis afficher le résultat pour validation
	r4.multiplier( r2 );
	std::cout << "r4 = r4 * r2 >>> r4 = " << r4 << std::endl;		// devrait afficher 11/5, 2.2

	// Attendre confirmation pour fermer la console 
	std::cout << "\n\nPressez une touche pour terminer..." << std::endl;
	_getch();


	return 0;
}


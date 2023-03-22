/*=============================================================
Programmeur : Marco Lavoie
Fichier     : Exercice_7_2.cpp
Description : Fonctions membres manipulant des instances const.
Date        : 2010/03/08
Source      : Notes de cours 14728 ORD, Marco Lavoie, p. 7.33
===============================================================*/

#include "stdafx.h"		// exclusif à Visual Studio

#include <iostream>		// cout, endl
#include <conio.h>		// _getch()
#include "Donnees.h"	// déclaration de la classe Donnees

using std::cout;
using std::endl;

// Programme principal: test la classe Donnees avec une
//                      instance const.
int _tmain(int argc, _TCHAR* argv[]) {
	const double v[] = { 3.2, 5.6, 3.9 };
	Donnees data( v, 3 );			// instance const initialisée

	// Ajouter des valeurs aux données
	data.ajout( 1.7 ).ajout( 9.4 );

	// Afficher la moyenne des données
	cout << data.moyenne() << endl;

	// Éviter que la console soit fermée immédiatement
	cout << "\nPressez une touche pour terminer...";
	_getch();

	return 0;
} // _tmain


/*=============================================================
Programmeur : Marco Lavoie
Fichier     : Exercice_7_1.cpp
Description :�Fonctions membres manipulant des instances const.
Date        : 2010/03/08
Source      : Notes de cours 14728 ORD, Marco Lavoie, p. 7.20
===============================================================*/

#include "stdafx.h"		// exclusif � Visual Studio

#include <iostream>		// cout, endl
#include <conio.h>		// _getch()
#include "Donnees.h"	// d�claration de la classe Donnees

using std::cout;
using std::endl;

// Programme principal: test la classe Donnees avec une
//                      instance const.
int _tmain(int argc, _TCHAR* argv[]) {
	const double v[] = { 3.2, 5.6, 3.9 };
	const Donnees data( v, 3 );			// instance const initialis�e

	// Afficher la moyenne des donn�es
	cout << data.moyenne() << endl;

	// �viter que la console soit ferm�e imm�diatement
	cout << "\nPressez une touche pour terminer...";
	_getch();

	return 0;
} // _tmain


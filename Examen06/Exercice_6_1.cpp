/*=============================================================
Programmeur : Marco Lavoie
Fichier     : Exercice_6_1.cpp
Description : Code de figure 6.12 dans fichiers séparés.
Date        : 2010/02/11
Source      : Notes de cours 14728 ORD, Marco Lavoie, p. 6.30
===============================================================*/

#include "stdafx.h"		// exclusif à Visual Studio

#include <iostream>
#include "date.h"		// déclaration de la classe Date

using std::cout;
using std::endl;

// Programme simple testant le constructeur et l'affectation par 
// copie de la classe Date.
int main() {
	Date date1( 4, 7, 1993 ), date2; // date2 ajuste par défaut à 1/1/1990

	cout << "date1 = ";
	date1.afficher();
	cout << "\ndate2 = ";
	date2.afficher();

	date2 = date1;  // affectation par copie au membre par défaut.
	cout << "\n\nApres copie au membre par defaut, date2 = ";
	date2.afficher();
	cout << endl;

	return 0;
} // _tmain


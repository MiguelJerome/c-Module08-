/*=============================================================
Programmeur : Marco Lavoie
Fichier     : Devoir_7.cpp
Description : Surcharge d'opérateurs dans la classe Rationnel
Date        : 2010/04/01
Source      : Notes de cours de 14728 ORD, Marco Lavoie, 8.44
=============================================================*/

#include "stdafx.h"					// exclusif à Visual Studio

#include <iostream>					// cin, cout et endl
#include <iomanip>					// setw()
#include <conio.h>					// _getch()

#include "Rationnel.h"

using std::cin;
using std::cout;
using std::endl;

// Programme principal : teste la classe Rationnel
int _tmain(int argc, _TCHAR* argv[])
{
	Rationnel r1(1, 2), r2(3, 4), r3(10, 5), r4;

	cout << " Rationnel == Rationnel: " << (((r1 == r1) == true) && ((r1 == r2) == false) ? "Succes" : "Echec") << endl;
	cout << " Rationnel == entier   : " << (((r3 == 2 ) == true) && ((r3 == 10) == false) ? "Succes" : "Echec") << endl;
	cout << " entier == Rationnel   : " << (((2  == r3) == true) && ((10 == r3) == false) ? "Succes" : "Echec") << endl;
	cout << endl;

	cout << " Rationnel != Rationnel: " << (((r1 != r1) == false) && ((r1 != r2) == true) ? "Succes" : "Echec") << endl;
	cout << " Rationnel != entier   : " << (((r3 != 2 ) == false) && ((r3 != 10) == true) ? "Succes" : "Echec") << endl;
	cout << " entier != Rationnel   : " << (((2  != r3) == false) && ((10 != r3) == true) ? "Succes" : "Echec") << endl;
	cout << endl;

	cout << " Rationnel < Rationnel : " << (((r1 < r1) == false) && ((r1 < r2) == true ) ? "Succes" : "Echec") << endl;
	cout << " Rationnel < entier    : " << (((r1 < 1 ) == true ) && ((r3 < 2 ) == false) ? "Succes" : "Echec") << endl;
	cout << " entier < Rationnel    : " << (((1  < r3) == true ) && ((2  < r3) == false) ? "Succes" : "Echec") << endl;
	cout << endl;

	cout << " Rationnel <= Rationnel: " << (((r1 <= r1) == true) && ((r2 <= r1) == false) ? "Succes" : "Echec") << endl;
	cout << " Rationnel <= entier   : " << (((r1 <= 1 ) == true) && ((r3 <= 2 ) == true ) ? "Succes" : "Echec") << endl;
	cout << " entier <= Rationnel   : " << (((2  <= r3) == true) && ((3  <= r3) == false) ? "Succes" : "Echec") << endl;
	cout << endl;

	cout << " Rationnel > Rationnel : " << (((r1 > r1) == false) && ((r2 > r1) == true ) ? "Succes" : "Echec") << endl;
	cout << " Rationnel > entier    : " << (((r3 > 1 ) == true ) && ((r1 > 1 ) == false) ? "Succes" : "Echec") << endl;
	cout << " entier > Rationnel    : " << (((2  > r3) == false) && ((3  > r3) == true ) ? "Succes" : "Echec") << endl;
	cout << endl;

	cout << " Rationnel >= Rationnel: " << (((r1 >= r1) == true ) && ((r2 >= r1) == true ) ? "Succes" : "Echec") << endl;
	cout << " Rationnel >= entier   : " << (((r1 >= 1 ) == false) && ((r3 >= 2 ) == true ) ? "Succes" : "Echec") << endl;
	cout << " entier >= Rationnel   : " << (((2  >= r3) == true ) && ((1  >= r3) == false) ? "Succes" : "Echec") << endl;
	cout << endl;

	cout << " Rationnel + Rationnel : " << ((r1 + r2) == Rationnel(5, 4) ? "Succes" : "Echec") << endl;
	cout << " Rationnel + entier    : " << ((r1 + 1 ) == Rationnel(3, 2) ? "Succes" : "Echec") << endl;
	cout << " entier + Rationnel    : " << ((2  + r3) == Rationnel(4, 1) ? "Succes" : "Echec") << endl;
	cout << endl;

	cout << " Rationnel - Rationnel : " << ((r2 - r1) == Rationnel( 1, 4) ? "Succes" : "Echec") << endl;
	cout << " Rationnel - entier    : " << ((r2 - 1 ) == Rationnel(-1, 4) ? "Succes" : "Echec") << endl;
	cout << " entier - Rationnel    : " << ((1  - r1) == Rationnel( 1, 2) ? "Succes" : "Echec") << endl;
	cout << endl;

	cout << " Rationnel * Rationnel : " << ((r1 * r2) == Rationnel(3, 8) ? "Succes" : "Echec") << endl;
	cout << " Rationnel * entier    : " << ((r2 * 2 ) == Rationnel(3, 2) ? "Succes" : "Echec") << endl;
	cout << " entier * Rationnel    : " << ((2  * r1) == Rationnel(1, 1) ? "Succes" : "Echec") << endl;
	cout << endl;

	cout << " Rationnel / Rationnel : " << ((r1 / r2) == Rationnel(2, 3) ? "Succes" : "Echec") << endl;
	cout << " Rationnel / entier    : " << ((r3 / 2 ) == Rationnel(1, 1) ? "Succes" : "Echec") << endl;
	cout << " entier / Rationnel    : " << ((2  / r1) == Rationnel(4, 1) ? "Succes" : "Echec") << endl;
	cout << endl;

	cout << " Rationnel = Rationnel : " << ((r4 = r1) == Rationnel(1, 2) && r4 == Rationnel(1, 2)? "Succes" : "Echec") << endl;
	cout << " Rationnel = entier    : " << ((r4 = 2 ) == Rationnel(2, 1) && r4 == Rationnel(2, 1)? "Succes" : "Echec") << endl;
	cout << endl;

	cout << " Rationnel += Rationnel: " << ((r4 += r1) == Rationnel(5, 2) && r4 == Rationnel(5, 2)? "Succes" : "Echec") << endl;
	cout << " Rationnel += entier   : " << ((r4 += 2 ) == Rationnel(9, 2) && r4 == Rationnel(9, 2)? "Succes" : "Echec") << endl;
	cout << endl;

	cout << " Rationnel -= Rationnel: " << ((r4 -= r2) == Rationnel(15, 4) && r4 == Rationnel(15, 4)? "Succes" : "Echec") << endl;
	cout << " Rationnel -= entier   : " << ((r4 -= 1 ) == Rationnel(11, 4) && r4 == Rationnel(11, 4)? "Succes" : "Echec") << endl;
	cout << endl;

	cout << " Rationnel *= Rationnel: " << ((r4 *= r1) == Rationnel(11, 8) && r4 == Rationnel(11, 8)? "Succes" : "Echec") << endl;
	cout << " Rationnel *= entier   : " << ((r4 *= 2 ) == Rationnel(11, 4) && r4 == Rationnel(11, 4)? "Succes" : "Echec") << endl;
	cout << endl;

	cout << " Rationnel /= Rationnel: " << ((r4 /= r1) == Rationnel(11, 2) && r4 == Rationnel(11, 2)? "Succes" : "Echec") << endl;
	cout << " Rationnel /= entier   : " << ((r4 /= 2 ) == Rationnel(11, 4) && r4 == Rationnel(11, 4)? "Succes" : "Echec") << endl;
	cout << endl;

	cout << " ++Rationnel           : " << (++r4 == Rationnel(15, 4) && r4 == Rationnel(15, 4)? "Succes" : "Echec") << endl;
	cout << " Rationnel++           : " << (r4++ == Rationnel(15, 4) && r4 == Rationnel(19, 4)? "Succes" : "Echec") << endl;
	cout << endl;

	cout << " --Rationnel           : " << (--r4 == Rationnel(15, 4) && r4 == Rationnel(15, 4)? "Succes" : "Echec") << endl;
	cout << " Rationnel--           : " << (r4-- == Rationnel(15, 4) && r4 == Rationnel(11, 4)? "Succes" : "Echec") << endl;
	cout << endl;

	// Attendre confirmation pour fermer la console 
	std::cout << "\nPressez une touche pour terminer..." << std::endl;
	_getch();

	return 0;
}


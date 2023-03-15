#include "pch.h"
#include "devoir_5.h"
#include "Rationnel.h"

#include <iostream>
#include <conio.h>	
#include <iomanip>
#include<windows.h>

using namespace std;

// Fonction d'affichage de fraction.
// Paramètres:
//   chaine : étiquette à afficher avant la fraction
//   r      : fraction à afficher
void afficherRationnel(const char* chaine, Rationnel& r) {
	std::cout << chaine << '\t';
	r.affichageFraction();
	std::cout << ", \t";
	r.affichageFlottant();
	std::cout << std::endl;
}

// Programme principal : demande le message à transmettre puis transmet celui-ci
// en Morse (visuellement dans la console et de façon sonore)
int main(int argc, char* argv[]) {
	SetConsoleOutputCP(1252);

	cout << pgcd(2, 4) << endl;
	cout << pgcd(4, 2) << endl;

	Rationnel r1;			// devrait être 1/1
	Rationnel r2(2);		// devrait être 2/1
	Rationnel r3(6, 9);		// devrait être 2/3
	Rationnel r4(3, -5);	// devrait être -3/5 (le signe doit toujours être attribué au numérateur)

	// Afficher les instances pour validation
	afficherRationnel("r1 = ", r1);		// devrait afficher 1/1, 1
	afficherRationnel("r2 = ", r2);		// devrait afficher 2/1, 2
	afficherRationnel("r3 = ", r3);		// devrait afficher 2/3, 0.666667
	afficherRationnel("r4 = ", r4);		// devrait afficher -3/5, -0.6

	// Tester l'addition de r2 à r4, puis afficher le résultat pour validation
	r4.additionner(r2);
	afficherRationnel("\nr4 = r4 + r2 >>> r4 = ", r4);		// devrait afficher 7/5, 1.4

	// Tester la soustraction de r3 à r4, puis afficher le résultat pour validation
	r4.soustraire(r3);
	afficherRationnel("r4 = r4 - r3 >>> r4 = ", r4);		// devrait afficher 11/15, 0.733333

	// Tester la division de r4 à r3, puis afficher le résultat pour validation
	r4.diviser(r3);
	afficherRationnel("r4 = r4 / r3 >>> r4 = ", r4);		// devrait afficher 11/10, 1.1

	// Tester la multiplication de r2 à r4, puis afficher le résultat pour validation
	r4.multiplier(r2);
	afficherRationnel("r4 = r4 * r2 >>> r4 = ", r4);		// devrait afficher 11/5, 2.2

	// Attendre confirmation pour fermer la console 
	std::cout << "\nPressez une touche pour terminer..." << std::endl;
	_getch();

	return 0;
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

// D�finitions des fonctions membres de la classe Donnees

#include "Donnees.h"

// Constructeur par d�faut: aucune valeur g�r�es
Donnees::Donnees( int sz ) {
	// Cr�er le tableau de stockage
	szValeurs = sz;
	valeurs   = new double[ szValeurs ];

	nbValeurs = 0;
} // DOnnees

// Constructeur param�tr�: stocke les valeurs fournies dans l'instance
Donnees::Donnees( const double *val, int nb, int sz ) {
	// Cr�er le tableau de stockage
	szValeurs = sz;
	valeurs   = new double[ szValeurs ];

	// Copier les valeurs dans l'attribut de stockage
	for ( int i = 0; i < nb; i++ )
		valeurs[i] = val[i];
	nbValeurs = nb;		// Nombre de valeurs dans l'attribut de stockage
} // Donnees

// Fonction permettant d'ajuouter une donn�es au tableau de stockage.
// La fonction retourne this de sorte que ses invocations puissent
// �tre encha�n�es.
Donnees & Donnees::ajout( double v ) {
	// Ajouter la valeur au tableau de stockage (s'il reste de la place)
	if ( nbValeurs < szValeurs ) {
		valeurs[ nbValeurs ] = v;
		nbValeurs++;
	}

	return *this;
} // ajout

// Fonction membre retournant la moyenne des valeurs stock�es
// dans l'instance.
double Donnees::moyenne() const {
	double somme = 0.0;

	// Faire la somme des valeurs stock�es
	for ( int i = 0; i < nbValeurs; i++ )
		somme += valeurs[i];

	// Calculer et retourner la moyenne
	return somme / nbValeurs;
} // moyenne

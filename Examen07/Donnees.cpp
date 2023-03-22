// Définitions des fonctions membres de la classe Donnees

#include "Donnees.h"

// Constructeur par défaut: aucune valeur gérées
Donnees::Donnees( int sz ) {
	// Créer le tableau de stockage
	szValeurs = sz;
	valeurs   = new double[ szValeurs ];

	nbValeurs = 0;
} // DOnnees

// Constructeur paramétré: stocke les valeurs fournies dans l'instance
Donnees::Donnees( const double *val, int nb, int sz ) {
	// Créer le tableau de stockage
	szValeurs = sz;
	valeurs   = new double[ szValeurs ];

	// Copier les valeurs dans l'attribut de stockage
	for ( int i = 0; i < nb; i++ )
		valeurs[i] = val[i];
	nbValeurs = nb;		// Nombre de valeurs dans l'attribut de stockage
} // Donnees

// Fonction permettant d'ajuouter une données au tableau de stockage.
// La fonction retourne this de sorte que ses invocations puissent
// être enchaînées.
Donnees & Donnees::ajout( double v ) {
	// Ajouter la valeur au tableau de stockage (s'il reste de la place)
	if ( nbValeurs < szValeurs ) {
		valeurs[ nbValeurs ] = v;
		nbValeurs++;
	}

	return *this;
} // ajout

// Fonction membre retournant la moyenne des valeurs stockées
// dans l'instance.
double Donnees::moyenne() const {
	double somme = 0.0;

	// Faire la somme des valeurs stockées
	for ( int i = 0; i < nbValeurs; i++ )
		somme += valeurs[i];

	// Calculer et retourner la moyenne
	return somme / nbValeurs;
} // moyenne

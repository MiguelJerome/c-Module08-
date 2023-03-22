// Déclaration de la classe Donnees

#ifndef DONNEES_H
#define DONNEES_H

const int MAX = 100;	// Nombre maximal de valeurs gérées par la classe

// Déclaration de classe Donnees
class Donnees {
public:
	Donnees( int = 100 );                      // constructeur par défaut
	Donnees( const double *, int, int = 100 ); // Constructeur paramétré

	Donnees & ajout( double );                 // ajoute une donnée à valeurs[]
	double    moyenne() const;                 // calcule la moyenne des données

private:
	double *valeurs;                           // stockage de données
	int     nbValeurs,                         // nombre de données dans valeurs[]
			szValeurs;                         // taille du tableau valeurs[]
}; // Donnees

#endif

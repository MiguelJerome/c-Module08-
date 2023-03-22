// D�claration de la classe Donnees

#ifndef DONNEES_H
#define DONNEES_H

const int MAX = 100;	// Nombre maximal de valeurs g�r�es par la classe

// D�claration de classe Donnees
class Donnees {
public:
	Donnees( int = 100 );                      // constructeur par d�faut
	Donnees( const double *, int, int = 100 ); // Constructeur param�tr�

	Donnees & ajout( double );                 // ajoute une donn�e � valeurs[]
	double    moyenne() const;                 // calcule la moyenne des donn�es

private:
	double *valeurs;                           // stockage de donn�es
	int     nbValeurs,                         // nombre de donn�es dans valeurs[]
			szValeurs;                         // taille du tableau valeurs[]
}; // Donnees

#endif

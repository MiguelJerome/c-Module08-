// Déclaration de la classe Date

#ifndef DATE_H
#define DATE_H

// Classe simple Date
class Date {
	public:
		Date( int = 1, int = 1, int = 1990 );	// Constructeur par défaut

		void afficher();						// Affiche la date en format jj-mm-aaaa
		void jourSuivant();						// Incrémente la date d'une journée
	private:
		void validerAttributs();				// S'assure que la date est valide (et la corrige au besoin)

		int jour;								// 1 à X où X varie selonb le mois et l'année (bisextile)
		int mois;								// 1 à 12
		int annee;								// 0 ou plus
}; // Date

#endif

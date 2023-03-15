// D�claration de la classe Date

#ifndef DATE_H
#define DATE_H

// Classe simple Date
class Date {
	public:
		Date( int = 1, int = 1, int = 1990 );	// Constructeur par d�faut

		void afficher();						// Affiche la date en format jj-mm-aaaa
		void jourSuivant();						// Incr�mente la date d'une journ�e
	private:
		void validerAttributs();				// S'assure que la date est valide (et la corrige au besoin)

		int jour;								// 1 � X o� X varie selonb le mois et l'ann�e (bisextile)
		int mois;								// 1 � 12
		int annee;								// 0 ou plus
}; // Date

#endif

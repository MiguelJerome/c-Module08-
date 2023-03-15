#include "pch.h"
#include "temps.h"

Temps::Temps(int heure, int minutes, int seconde) : heure(heure), minutes(minutes), seconde(seconde) {
}

void Temps::ajusterTemps(int, int, int) {
}

void ajusterTemps(int, int, int) {
}

bool Temps::validerTemps() const {
    return (heure >= 0 && heure <= 23) &&
        (minutes >= 0 && minutes <= 59) &&
        (seconde >= 0 && seconde <= 59);
}

// surcharge fonction amie
Temps operator+(const Temps& gauche, const Temps& droite) {
    Temps resultat;
    int   secG = gauche.heure * 3600 + gauche.minutes * 60 + gauche.seconde;
    int   secD = droite.heure * 3600 + droite.minutes * 60 + droite.seconde;
    int   secRes = secG + secD;

    resultat.heure = secRes / 3600;    // extraire les heures
    secRes = resultat.heure % 3600;    // secondes restantes

    resultat.minutes = secRes / 60;    // extraire les minutes restantes
    secRes = resultat.minutes % 60;     // secondes restantes

    resultat.seconde = secRes;

    return resultat;
}

// surcharge fonction membre
/*
Temps Temps::operator+(const Temps& droite) const {
    // this -> operande de gauche
    Temps resultat;
    
    int   secG = this->heure * 3600 + this->minutes * 60 + this->seconde;
    int   secD = droite.heure * 3600 + droite.minutes * 60 + droite.seconde;
    int   secRes = secG + secD;
    
    int secD = droite.heure * 3600 + droite.minutes * 60 + droite.seconde;
    resultat = *this + secD;
    return resultat;                   // retourner l'heure résultante 
}
*/

std::ostream& operator<<(std::ostream& ostr, Temps& temps) {
    ostr << temps.heure << ':' << temps.minutes << ":" << temps.seconde;
    return ostr;
}
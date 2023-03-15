#pragma once
#include <ostream>

#ifndef TEMPS_H   // Est-ce que la variable de précompilation existe?
#define TEMPS_H   // Sinon, définir la variable de précompilation

class Temps {
    // Surcharge via fonction amie
    friend Temps operator+(const Temps&, const Temps&);

    friend std::ostream& operator<<(std::ostream&, Temps&);

    private:
        int heure;
        int minutes; 
        int seconde;

    public:
        Temps(int = 0, int = 0, int = 0);
        void ajusterTemps(int, int, int);
        bool validerTemps() const;
        
        // L'argument de gauche (gauche) est de même classe que la valeur de retour (i.e. type Temps)
        // L'opérateur peut dans ces cas être surchargé via une fonction membre de la classe
 //     Temps operator+(const Temps& droite) const;
};
#endif





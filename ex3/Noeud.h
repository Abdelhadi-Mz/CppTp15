#ifndef NOEUD_H
#define NOEUD_H

#include <string>

class Noeud {
public:
    int cle;
    std::string valeur;
    Noeud* suivant;

    Noeud(int c, const std::string& v) : cle(c), valeur(v), suivant(nullptr) {}
};

#endif

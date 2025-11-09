#include <iostream>
#include "ListeChainee.h"

int main() {
    ListeChainee liste;
    liste.ajouterDebut(3);
    liste.ajouterDebut(1);
    liste.ajouterFin(5);
    liste.ajouterFin(7);
    std::cout << "Liste : ";
    liste.afficher();
    std::cout << "Taille = " << liste.taille() << std::endl;
    liste.supprimer(5);
    std::cout << "Apres suppression de 5 : ";
    liste.afficher();
    std::cout << "Iteration avec iterateur : ";
    for (auto it = liste.begin(); it != liste.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    return 0;
}

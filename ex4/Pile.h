#ifndef PILE_H
#define PILE_H

#include <iostream>
#include <stdexcept>

template <typename T>
class Pile {
private:
    struct Noeud {
        T valeur;
        Noeud* suivant;
        Noeud(T v) : valeur(v), suivant(nullptr) {}
    };

    Noeud* sommetPile;
    int nbElements;

public:
    Pile() : sommetPile(nullptr), nbElements(0) {}

    ~Pile() {
        while (!estVide()) {
            depiler();
        }
    }

    bool estVide() const {
        return sommetPile == nullptr;
    }

    void empiler(T element) {
        Noeud* nouveau = new Noeud(element);
        nouveau->suivant = sommetPile;
        sommetPile = nouveau;
        nbElements++;
    }

    T depiler() {
        if (estVide()) {
            throw std::underflow_error("Erreur : tentative de depilement d'une pile vide !");
        }
        Noeud* temp = sommetPile;
        T valeur = temp->valeur;
        sommetPile = sommetPile->suivant;
        delete temp;
        nbElements--;
        return valeur;
    }

    T sommet() const {
        if (estVide()) {
            throw std::underflow_error("Erreur : pile vide !");
        }
        return sommetPile->valeur;
    }

    int taille() const {
        return nbElements;
    }

    void afficher() const {
        if (estVide()) {
            std::cout << "Pile vide." << std::endl;
            return;
        }
        Noeud* courant = sommetPile;
        std::cout << "Sommet -> ";
        while (courant != nullptr) {
            std::cout << courant->valeur << " -> ";
            courant = courant->suivant;
        }
        std::cout << "NULL" << std::endl;
    }

    void inverser() {
        if (estVide() || sommetPile->suivant == nullptr) return;
        Noeud* precedent = nullptr;
        Noeud* courant = sommetPile;
        Noeud* suivant = nullptr;

        while (courant != nullptr) {
            suivant = courant->suivant;
            courant->suivant = precedent;
            precedent = courant;
            courant = suivant;
        }
        sommetPile = precedent;
    }
};

#endif

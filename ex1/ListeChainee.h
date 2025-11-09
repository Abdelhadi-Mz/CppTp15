#ifndef LISTECHAINEE_H
#define LISTECHAINEE_H

#include <iostream>
#include "Noeud.h"

class ListeChainee {
private:
    Noeud* tete;
    int nbElements;

public:
    class Iterator {
    private:
        Noeud* courant;
    public:
        Iterator(Noeud* n) : courant(n) {}
        bool operator!=(const Iterator& other) const { return courant != other.courant; }
        int operator*() const { return courant->valeur; }
        Iterator& operator++() { 
            if (courant) courant = courant->suivant; 
            return *this; 
        }
    };

    ListeChainee() : tete(nullptr), nbElements(0) {}

    ~ListeChainee() {
        Noeud* courant = tete;
        while (courant != nullptr) {
            Noeud* temp = courant;
            courant = courant->suivant;
            delete temp;
        }
    }

    void ajouterDebut(int valeur) {
        Noeud* nouveau = new Noeud(valeur);
        nouveau->suivant = tete;
        tete = nouveau;
        nbElements++;
    }

    void ajouterFin(int valeur) {
        Noeud* nouveau = new Noeud(valeur);
        if (tete == nullptr) {
            tete = nouveau;
        } else {
            Noeud* courant = tete;
            while (courant->suivant != nullptr) {
                courant = courant->suivant;
            }
            courant->suivant = nouveau;
        }
        nbElements++;
    }

    void supprimer(int valeur) {
        if (tete == nullptr) return;
        if (tete->valeur == valeur) {
            Noeud* temp = tete;
            tete = tete->suivant;
            delete temp;
            nbElements--;
            return;
        }
        Noeud* courant = tete;
        while (courant->suivant != nullptr && courant->suivant->valeur != valeur) {
            courant = courant->suivant;
        }
        if (courant->suivant != nullptr) {
            Noeud* temp = courant->suivant;
            courant->suivant = courant->suivant->suivant;
            delete temp;
            nbElements--;
        }
    }

    void afficher() const {
        Noeud* courant = tete;
        while (courant != nullptr) {
            std::cout << courant->valeur << " -> ";
            courant = courant->suivant;
        }
        std::cout << "NULL" << std::endl;
    }

    int taille() const { return nbElements; }

    Iterator begin() const { return Iterator(tete); }
    Iterator end() const { return Iterator(nullptr); }
};

#endif

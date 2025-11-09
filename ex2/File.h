#ifndef FILE_H
#define FILE_H

#include <iostream>
#include <stdexcept>
#include "Noeud.h"

class File {
private:
    Noeud* tete;
    Noeud* queue;
    int tailleMax;
    int tailleActuelle;

public:
    File(int max = 10) : tete(nullptr), queue(nullptr), tailleMax(max), tailleActuelle(0) {}

    ~File() {
        while (!estVide()) {
            defiler();
        }
    }

    bool estVide() const {
        return tete == nullptr;
    }

    bool estPleine() const {
        return tailleActuelle >= tailleMax;
    }

    void enfiler(int valeur) {
        if (estPleine()) {
            std::cout << "File pleine, impossible d'enfiler " << valeur << std::endl;
            return;
        }
        Noeud* nouveau = new Noeud(valeur);
        if (estVide()) {
            tete = queue = nouveau;
        } else {
            queue->suivant = nouveau;
            queue = nouveau;
        }
        tailleActuelle++;
        std::cout << valeur << " ajoute a la file." << std::endl;
    }

    int defiler() {
        if (estVide()) {
            throw std::underflow_error("Erreur : tentative de defilement d'une file vide !");
        }
        Noeud* temp = tete;
        int valeur = temp->valeur;
        tete = tete->suivant;
        if (tete == nullptr) queue = nullptr;
        delete temp;
        tailleActuelle--;
        return valeur;
    }

    void afficher() const {
        if (estVide()) {
            std::cout << "File vide." << std::endl;
            return;
        }
        Noeud* courant = tete;
        std::cout << "File : ";
        while (courant != nullptr) {
            std::cout << courant->valeur << " <- ";
            courant = courant->suivant;
        }
        std::cout << "NULL" << std::endl;
    }

    int taille() const {
        return tailleActuelle;
    }
};

#endif

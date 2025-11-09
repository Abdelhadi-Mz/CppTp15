#ifndef TABLE_HACHAGE_H
#define TABLE_HACHAGE_H

#include <iostream>
#include <string>
#include <vector>
#include "Noeud.h"

class TableHachage {
private:
    std::vector<Noeud*> table;
    int taille;

    int fonctionHachage(int cle) const {
        return cle % taille;
    }

public:
    TableHachage(int t = 10) : taille(t) {
        table.resize(taille, nullptr);
    }

    ~TableHachage() {
        for (int i = 0; i < taille; i++) {
            Noeud* courant = table[i];
            while (courant != nullptr) {
                Noeud* temp = courant;
                courant = courant->suivant;
                delete temp;
            }
        }
    }

    void inserer(int cle, const std::string& valeur) {
        int index = fonctionHachage(cle);
        Noeud* nouveau = new Noeud(cle, valeur);
        nouveau->suivant = table[index];
        table[index] = nouveau;
        std::cout << "Element insere : (" << cle << ", " << valeur << ") dans la case " << index << std::endl;
    }

    std::string rechercher(int cle) const {
        int index = fonctionHachage(cle);
        Noeud* courant = table[index];
        while (courant != nullptr) {
            if (courant->cle == cle) {
                return courant->valeur;
            }
            courant = courant->suivant;
        }
        return "Cle non trouvee";
    }

    void supprimer(int cle) {
        int index = fonctionHachage(cle);
        Noeud* courant = table[index];
        Noeud* precedent = nullptr;

        while (courant != nullptr && courant->cle != cle) {
            precedent = courant;
            courant = courant->suivant;
        }

        if (courant == nullptr) {
            std::cout << "Cle " << cle << " non trouvee." << std::endl;
            return;
        }

        if (precedent == nullptr) {
            table[index] = courant->suivant;
        } else {
            precedent->suivant = courant->suivant;
        }

        delete courant;
        std::cout << "Cle " << cle << " supprimee." << std::endl;
    }

    void afficher() const {
        for (int i = 0; i < taille; i++) {
            std::cout << "Case " << i << ": ";
            Noeud* courant = table[i];
            if (!courant) {
                std::cout << "vide";
            } else {
                while (courant != nullptr) {
                    std::cout << "(" << courant->cle << ", " << courant->valeur << ") -> ";
                    courant = courant->suivant;
                }
                std::cout << "NULL";
            }
            std::cout << std::endl;
        }
    }
};

#endif

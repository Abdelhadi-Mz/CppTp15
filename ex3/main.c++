#include <iostream>
#include "TableHachage.h"

int main() {
    TableHachage table(5);
    int choix, cle;
    std::string valeur;

    do {
        std::cout << "\n--- MENU TABLE DE HACHAGE ---" << std::endl;
        std::cout << "1. Inserer" << std::endl;
        std::cout << "2. Rechercher" << std::endl;
        std::cout << "3. Supprimer" << std::endl;
        std::cout << "4. Afficher la table" << std::endl;
        std::cout << "5. Quitter" << std::endl;
        std::cout << "Choix : ";
        std::cin >> choix;

        switch (choix) {
            case 1:
                std::cout << "Entrer la cle : ";
                std::cin >> cle;
                std::cout << "Entrer la valeur : ";
                std::cin >> valeur;
                table.inserer(cle, valeur);
                break;

            case 2:
                std::cout << "Entrer la cle a rechercher : ";
                std::cin >> cle;
                std::cout << "Valeur : " << table.rechercher(cle) << std::endl;
                break;

            case 3:
                std::cout << "Entrer la cle a supprimer : ";
                std::cin >> cle;
                table.supprimer(cle);
                break;

            case 4:
                table.afficher();
                break;

            case 5:
                std::cout << "Fin du programme." << std::endl;
                break;

            default:
                std::cout << "Choix invalide." << std::endl;
        }

    } while (choix != 5);

    return 0;
}

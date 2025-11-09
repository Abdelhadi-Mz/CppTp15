#include <iostream>
#include "File.h"

int main() {
    File f(5);
    int choix, val;

    do {
        std::cout << "\n--- MENU FILE D'ATTENTE ---" << std::endl;
        std::cout << "1. Enfiler (ajouter)" << std::endl;
        std::cout << "2. Defiler (retirer)" << std::endl;
        std::cout << "3. Afficher la file" << std::endl;
        std::cout << "4. Verifier si vide" << std::endl;
        std::cout << "5. Verifier si pleine" << std::endl;
        std::cout << "6. Quitter" << std::endl;
        std::cout << "Choix : ";
        std::cin >> choix;

        try {
            switch (choix) {
                case 1:
                    std::cout << "Entrer une valeur : ";
                    std::cin >> val;
                    f.enfiler(val);
                    break;
                case 2:
                    std::cout << "Element retire : " << f.defiler() << std::endl;
                    break;
                case 3:
                    f.afficher();
                    break;
                case 4:
                    std::cout << (f.estVide() ? "La file est vide." : "La file contient des elements.") << std::endl;
                    break;
                case 5:
                    std::cout << (f.estPleine() ? "La file est pleine." : "La file n'est pas pleine.") << std::endl;
                    break;
                case 6:
                    std::cout << "Fin du programme." << std::endl;
                    break;
                default:
                    std::cout << "Choix invalide." << std::endl;
            }
        } catch (const std::exception& e) {
            std::cerr << e.what() << std::endl;
        }

    } while (choix != 6);

    return 0;
}

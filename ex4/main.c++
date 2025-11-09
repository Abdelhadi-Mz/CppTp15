#include <iostream>
#include <string>
#include "Pile.h"

int main() {
    try {
        Pile<int> p1;
        p1.empiler(10);
        p1.empiler(20);
        p1.empiler(30);
        std::cout << "Pile d'entiers : ";
        p1.afficher();
        std::cout << "Sommet = " << p1.sommet() << std::endl;
        p1.inverser();
        std::cout << "Apres inversion : ";
        p1.afficher();

        Pile<std::string> p2;
        p2.empiler("Hello");
        p2.empiler("World");
        std::cout << "\nPile de chaines : ";
        p2.afficher();
        std::cout << "Depile : " << p2.depiler() << std::endl;
        p2.afficher();

        Pile<double> p3;
        p3.empiler(1.5);
        p3.empiler(3.14);
        p3.empiler(2.71);
        std::cout << "\nPile de doubles : ";
        p3.afficher();
        std::cout << "Sommet = " << p3.sommet() << std::endl;

        Pile<int> vide;
        std::cout << "\nTest pile vide : " << std::endl;
        vide.depiler(); 
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}

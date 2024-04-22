#include <iostream>
#include <vector>

#include "Schrage.hh"

int main ( int argc, char **argv ){

    Schrage pr;

    pr.read(argv[1]);

    std::vector<Zadanie> gotowaLista;
    gotowaLista.resize(100);

    std::cout << "Czas: " << pr.schrage(gotowaLista) << std::endl;

    pr.print();

    return 0;
}
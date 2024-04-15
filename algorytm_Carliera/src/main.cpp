#include <iostream>
#include <vector>

#include "problem_rpq.hh"

int main ( int argc, char **argv ){

    problem_rpq pr;

    pr.read(argv[1]);

    std::cout << "Zbior zadan przed: " << std::endl;
    pr.print();

    std::vector<zadanie> gotowa_lista;
    gotowa_lista.resize(pr.get_size());

    std::cout << pr.schrage(gotowa_lista) << std::endl;

    std::cout << "Zbior zadan po: " << std::endl;
    pr.print();

    return 0;
}
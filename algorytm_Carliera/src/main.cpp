#include <iostream>
#include <vector>

#include "problem_rpq.hh"

int main ( int argc, char **argv ){

    problem_rpq pr;

    pr.read(argv[1]);

    std::vector<zadanie> gotowa_lista;
    gotowa_lista.resize(pr.get_size());

    int c =  pr.schrage(gotowa_lista);
    std::cout << c << std::endl;

    for (int i=0; i<gotowa_lista.size(); ++i){
        std::cout << gotowa_lista[i];
    }

    std::cout << "Indeks b: " << pr.wyznacz_b(c, gotowa_lista) << std::endl;

    return 0;
}
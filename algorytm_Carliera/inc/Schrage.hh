#ifndef SCHRAGE_HH
#define SCHRAGE_HH

#include <iostream>
#include <fstream>
#include <vector>

#include "Zadanie.hh"

class Schrage {

    int _size;

    std::vector<Zadanie> _listaZadan;

    public:

    int read ( char *filename );

    void print ();

    int schrage (std::vector<Zadanie> &gotowaLista);


    /* Sorting */

    void quicksort_lista_zadan( int start, int end );
    void quicksort_gotowe_do_realizacji( int start, int end, std::vector<Zadanie> &doRealizacji);
    
    int partition_lista_zadan ( int start, int end );
    int partition_gotowe_do_realizacji ( int start, int end, std::vector<Zadanie> &doRealizacji);


};

#endif
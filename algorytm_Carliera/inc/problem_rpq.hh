#ifndef SZEREGOWANIE_HH
#define SZEREGOWANIE_HH

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

#include "zadanie.hh"

class problem_rpq{

    int _size;

    std::vector<zadanie> _zbior_zadan;

    std::vector<zadanie> _gotowa_lista;

    std::vector<zadanie> _gotowe_do_realizacji;

    void init();

    public:

    problem_rpq() = default;

    problem_rpq(std::vector<zadanie> &zbior_zadan){
        
        _zbior_zadan = zbior_zadan;

        /* Rezerwacja miejsca dla wektorów */
        _gotowa_lista.reserve(_zbior_zadan.size());
        _gotowe_do_realizacji.reserve(_zbior_zadan.size());
    }

    int get_size () { return _size; }

    int read ( char *filename );

    void print ();

    int schrage ();

    int preschrage ();

    int carlier ();

    void quicksort_zbior_zadan( int start, int end );

    void quicksort_gotowe_do_realizacji( int start, int end);

    int partition_zbior_zadan ( int start, int end );

    int partition_gotowe_do_realizacji ( int start, int end );

};

#endif
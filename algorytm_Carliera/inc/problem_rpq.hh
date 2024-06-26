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

    int _UB = -1;

    void init();

    public:

    problem_rpq() = default;

    problem_rpq(std::vector<zadanie> &zbior_zadan){
        
        _zbior_zadan = zbior_zadan;

        /* Rezerwacja miejsca dla wektorów */
        _gotowa_lista.resize(_zbior_zadan.size());
        _gotowe_do_realizacji.reserve(_zbior_zadan.size());
    }

    int get_size () { return _size; }

    int read ( char *filename );

    void print ();

    int schrage ( std::vector<zadanie> &gotowa_lista);

    int preschrage ();

    int wylicz_koniec ( int end, std::vector<zadanie> &permutacja );

    int wyznacz_b ( int Cmax, std::vector<zadanie> &permutacja );

    int wyznacz_a (  int c, int b, std::vector<zadanie> &permutacja );

    /*!
        \brief Wyznaczenie zadania interferencyjnego
        \par indeks zadania najdalszego
    */
    int wyznacz_c ( int a, int b, std::vector<zadanie> &permutacja );

    int suma_p ( int begin, int end, std::vector<zadanie> &permutacja );

    int carlier ();

    std::vector<zadanie>& carlier ( int UB, std::vector<zadanie> &permutacja );

    void quicksort_zbior_zadan( int start, int end );

    void quicksort_gotowe_do_realizacji( int start, int end);

    int partition_zbior_zadan ( int start, int end );

    int partition_gotowe_do_realizacji ( int start, int end );

    int find_minimum_r ( int begin, int end, std::vector<zadanie> &permutacja );

    int find_minimum_q ( int begin, int end, std::vector<zadanie> &permutacja );

    int wylicz_cmax ( std::vector<zadanie> &permutacja );

};

#endif
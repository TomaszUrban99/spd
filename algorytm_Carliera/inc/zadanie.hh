#ifndef ZADANIE_HH
#define ZADANIE_HH

#include <iostream>
#include <vector>

class zadanie {

    int _id; // identyfikator zadania
    int _r; // czas przygotowywania
    int _p; // czas wykonywania
    int _q;

    public:

    zadanie() = default;

    /*!
        \brief Konstruktor parametryczny klasy zadanie
    */
    zadanie(int r, int p, int q){
        _r = r;
        _p = p;
        _q = q;
    }

    void set_id ( int new_id ) {
        _id = new_id;
    }

    void set_p ( int new_p ) {
        _p = new_p;
    }

    int& get_id () { return _id; }

    int& get_r () { return _r; }

    int get_ra () const { return _r; }

    int& get_p () { return _p; }

    int get_pa () const { return _p; }

    int& get_q () { return _q; }
};

std::istream& operator>>( std::istream& input, zadanie& new_task);

std::ostream& operator<<( std::ostream& output, zadanie& task_to_write );

#endif
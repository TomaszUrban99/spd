#ifndef ZADANIE_HH
#define ZADANIE_HH

#include <iostream>
#include <vector>

class zadanie {

    int _id; // identyfikator zadania
    int _r; // czas przygotowania
    int _p; // czas wykonywania
    int _q; // czas dostarczenia
    int _t; // czas zakonczenia wykonywania zadania

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

    void set_t ( int new_t ) {
        _t = new_t;
    }

    int& get_id () { return _id; }

    int& get_r () { return _r; }

    int get_ra () const { return _r; }

    int& get_p () { return _p; }

    int get_pa () const { return _p; }

    int& get_q () { return _q; }

    int& get_t () { return _t; }
};

std::istream& operator>>( std::istream& input, zadanie& new_task);

std::ostream& operator<<( std::ostream& output, zadanie& task_to_write );

#endif
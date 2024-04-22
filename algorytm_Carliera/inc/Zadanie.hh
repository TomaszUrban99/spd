#ifndef ZADANIE_HH
#define ZADANIE_HH

#include <iostream>
#include <vector>

class Zadanie {

    int _id; // identyfikator zadania
    
    int _r; // czas przygotowania
    int _p; // czas wykonywania
    int _q; // czas dostarczenia
    int _t; // czas zakonczenia wykonywania zadania

    public:

    Zadanie() = default;

    /*!
        \brief Konstruktor parametryczny klasy zadanie
    */
    Zadanie(int r, int p, int q){
        _r = r;
        _p = p;
        _q = q;
    }

    /* --------------------------------- */

        int& get_id () { return _id; }

        void set_id ( int newID ) { _id = newID; }

    /* --------------------------------- */

    /* --------------------------------- */
    
        int& get_r () { return _r; }

        int get_r_const () const { return _r; }

    /* --------------------------------- */

    int& get_p () { return _p; }

    int get_p_const () const { return _p; }

    int& get_q () { return _q; }

    int get_q_const () { return _q; }

    int& get_t () { return _t; }

    void set_t ( int newT ) { _t = newT; }
};

std::istream& operator>>( std::istream& input, Zadanie& new_task);

std::ostream& operator<<( std::ostream& output, Zadanie& task_to_write );


#endif
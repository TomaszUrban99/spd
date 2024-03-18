#ifndef TASK_HH
#define TASK_HH

#include <iostream>
#include <fstream>

class task {

    int _id;
    int _r;
    int _p;

    public:

    /************ TASK CLASS CONSTRUCTOR *************/
    
    task ( int new_id, int new_r, int new_p ){
        _id = new_id;
        _r = new_r;
        _p = new_p;
    }

    task (){

    }

    /*************************************************/

    /************** TASK CLASS INTERFACE ************/
    
    int& get_id () { return _id; }

    int& get_r () { return _r; }

    int& get_p () { return _p; }

    void set_id ( int _set_id ) { _id = _set_id; }

    void set_r ( int new_r ) { _r = new_r; }

    void set_p ( int new_p ) { _p = new_p; }

    /************************************************/
};

std::istream& operator>>( std::istream& input, task& new_task);

std::ostream& operator<<( std::ostream& output, task& task_to_write );

#endif
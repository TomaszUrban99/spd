#ifndef TASK_HH
#define TASK_HH

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

    /*************************************************/

    /************** TASK CLASS INTERFACE ************/
    
    int& get_id () { return _id; }

    int& get_r () { return _r; }

    int& get_p () { return _p; }

    /************************************************/
};

#endif
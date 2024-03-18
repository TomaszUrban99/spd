#ifndef TASK_LIST_HH
#define TASK_LIST_HH

#include <iostream>

#include "task.hh"

class task_list {

    int _size = 0;
    task* _list_of_elements;

    public:

    /********** TASK_LIST CONSTRUCTOR AND DESTRUCTORS *********/

    ~task_list () { delete [] _list_of_elements; }

    /**********************************************************/

    /************** TASK_LIST INTERFACE ***********************/

    /*! \brief Return size of task list */
    int size () { return _size; }

    /*! \brief Return element on field with given index */
    task& operator[] ( int index ) {
            
        if ( index < _size && index >= 0 )
            return _list_of_elements[index];
    }


};

#endif
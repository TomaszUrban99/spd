#include "task_list.hh"

int task_list::read( char *file_name ){

    std::ifstream input;
    input.open(file_name);

    if ( input.fail() ){
        std::cerr << "Failed to open file" << std::endl;
        exit(3);
    }

    /* Read size of task list */
    input >> _size;

    /* Allocate list of elements */
    _list_of_elements = new task[_size];

    if ( _list_of_elements == NULL ){
        std::cerr << "Failed to allocate memory" << std::endl;
        exit(4);
    }

    /* Count number of read elements */
    int i = 0;

    while ( !input.eof() && i < _size ){

        input >> _list_of_elements[i];
        
        if ( input.fail() )
            return i;

        _list_of_elements[i].set_id(i);
        
        ++i;
    }

    return i;
}


void task_list::print(){

    for ( int i = 0; i < _size; ++i ){
        std::cout << _list_of_elements[i];
    }
}
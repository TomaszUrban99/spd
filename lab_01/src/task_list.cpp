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

int task_list::partition ( int start, int end ){
    
    int pivot = _list_of_elements[start].get_r();
 
    int count = 0;
    
    for (int i = start + 1; i <= end; i++) {
        if (_list_of_elements[i].get_r() <= pivot)
            count++;
    }
 
    // Giving pivot element its correct position
    int pivotIndex = start + count;
    std::swap(_list_of_elements[pivotIndex], _list_of_elements[start]);
 
    // Sorting left and right parts of the pivot element
    int i = start, j = end;
 
    while (i < pivotIndex && j > pivotIndex) {
 
        while (_list_of_elements[i].get_r() <= pivot) {
            i++;
        }
 
        while (_list_of_elements[j].get_r() > pivot) {
            j--;
        }
 
        if (i < pivotIndex && j > pivotIndex) {
            std::swap(_list_of_elements[i++], _list_of_elements[j--]);
        }
    }
 
    return pivotIndex;
}


void task_list::quicksort( int start, int end ){
        // base case
    if (start >= end)
        return;
 
    // partitioning the array
    int p = partition(start, end);
 
    // Sorting the left part
    quicksort(start, p - 1);
 
    // Sorting the right part
    quicksort(p + 1, end);
}
 
int task_list::jackson( char *file_name ){

    /* Read task from given file */
    read(file_name);

    /* Sort array */
    quicksort(0, _size-1);


    int time = 0;
    int temp_time;

    /* Calculate time of first element */
    
    time = _list_of_elements[0].get_r() 
            + _list_of_elements[0].get_p();

    for ( int i = 1; i < _size; ++i ){

        if ( time - _list_of_elements[i].get_r() < 0 ){
            
            time =  _list_of_elements[i].get_r()
                    + _list_of_elements[i].get_p();
        }
        else{
            time = time + _list_of_elements[i].get_p();
        }

    }

    return time;
}
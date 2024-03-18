#include <iostream>

#include "task_list.hh"

int main (int argc, char **argv){

    task_list new_list;

    std::cout << "Minimalny czas: " << new_list.jackson(argv[1]) << std::endl;
    
    return 0;
}
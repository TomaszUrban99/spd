#include <iostream>

#include "task_list.hh"

int main (int argc, char **argv){

    task_list new_list;

    new_list.read(argv[1]);

    new_list.print();

    return 0;
}
#include <iostream>
#include <vector>

#include "problem_rpq.hh"

int main ( int argc, char **argv ){

    problem_rpq pr;

    pr.read(argv[1]);

    std::cout << pr.preschrage() << std::endl;

    return 0;
}
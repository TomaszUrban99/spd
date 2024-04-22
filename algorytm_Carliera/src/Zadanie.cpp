#include "Zadanie.hh"

std::istream& operator>>( std::istream& input, Zadanie& new_task){

    input >> new_task.get_r();

    if (input.fail()){
        std::cerr << "Failed to read" << std::endl;
        exit(2);
    }

    input >> new_task.get_p();

    if (input.fail()){
        std::cerr << "Failed to read" << std::endl;
        exit(2);
    }

    input >> new_task.get_q();
    if (input.fail()){
        std::cerr << "Failed to read" << std::endl;
        exit(2);
    }

    return input;
}

std::ostream& operator<<( std::ostream& output, Zadanie& task_to_write ){

    output  << task_to_write.get_id() << " " << task_to_write.get_r() << " "
            << task_to_write.get_p() << " " << task_to_write.get_q() << " "
            << task_to_write.get_t() << std::endl;
        
    return output;
}
#include "task.hh"

std::istream& operator>>( std::istream& input, task& new_task){

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

    return input;
}

std::ostream& operator<<( std::ostream& output, task& task_to_write ){

    output  << task_to_write.get_id() << " " << task_to_write.get_r() << " "
            << task_to_write.get_p() << std::endl;
        
    return output;
}
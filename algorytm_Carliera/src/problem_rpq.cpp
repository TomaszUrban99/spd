#include "problem_rpq.hh"

void problem_rpq::init(){
    
    _zbior_zadan.resize(_size);
    
    /* Rezerwacja miejsca dla wektorów */
    _gotowa_lista.resize(_size);
    _gotowe_do_realizacji.reserve(_size);
}

int problem_rpq::partition_zbior_zadan ( int start, int end ){
    
    int pivot = _zbior_zadan[start].get_r();
 
    int count = 0;
    
    for (int i = start + 1; i <= end; i++) {
        if (_zbior_zadan[i].get_r() >= pivot)
            count++;
    }
 
    // Giving pivot element its correct position
    int pivotIndex = start + count;
    std::swap(_zbior_zadan[pivotIndex], _zbior_zadan[start]);
 
    // Sorting left and right parts of the pivot element
    int i = start, j = end;
 
    while (i < pivotIndex && j > pivotIndex) {
 
        while (_zbior_zadan[i].get_r() >= pivot) {
            i++;
        }
 
        while (_zbior_zadan[j].get_r() < pivot) {
            j--;
        }
 
        if (i < pivotIndex && j > pivotIndex) {
            std::swap(_zbior_zadan[i++], _zbior_zadan[j--]);
        }
    }
 
    return pivotIndex;
}

int problem_rpq::partition_gotowe_do_realizacji ( int start, int end ){
   
   int pivot = _gotowe_do_realizacji[start].get_q();
 
   int count = 0;
   
   for (int i = start + 1; i <= end; i++) {
       if (_gotowe_do_realizacji[i].get_q() <= pivot)
           count++;
   }
 
   // Giving pivot element its correct position
   int pivotIndex = start + count;
   std::swap(_gotowe_do_realizacji[pivotIndex], _gotowe_do_realizacji[start]);
 
   // Sorting left and right parts of the pivot element
   int i = start, j = end;
 
   while (i < pivotIndex && j > pivotIndex) {
 
       while (_gotowe_do_realizacji[i].get_q() <= pivot) {
           i++;
       }
 
       while (_gotowe_do_realizacji[j].get_q() > pivot) {
           j--;
       }
 
       if ((i < pivotIndex) && (j > pivotIndex)) {
           std::swap(_gotowe_do_realizacji[i++], _gotowe_do_realizacji[j--]);
       }
   }
 
   return pivotIndex;
}

/* Sortowanie malejaco na podstawie wartosci parametru r */
void problem_rpq::quicksort_zbior_zadan( int start, int end ){
        // base case
    if (start >= end)
        return;
 
    // partitioning the array
    int p = partition_zbior_zadan(start, end);
 
    // Sorting the left part
    quicksort_zbior_zadan(start, p - 1);
 
    // Sorting the right part
    quicksort_zbior_zadan(p + 1, end);
}

void problem_rpq::quicksort_gotowe_do_realizacji( int start, int end ){
        // base case
    if (start >= end)
        return;
 
    // partitioning the array
    int p = partition_gotowe_do_realizacji(start, end);
 
    // Sorting the left part
    quicksort_gotowe_do_realizacji(start, p - 1);
 
    // Sorting the right part
    quicksort_gotowe_do_realizacji(p + 1, end);
}

int problem_rpq::read ( char *file_name ){
    
    std::ifstream input;
    input.open(file_name);
    
    if ( input.fail() ){
        std::cerr << "Failed to open file" << std::endl;
        exit(3);
    }
    
    /* Read size of task list */
    input >> _size;
    
    /* Allocate list of elements */
    init();
    
    /* Count number of read elements */
    
    int i = 0;
    
    while ( !input.eof() && i < _size ){
        
        input >> _zbior_zadan[i];
    
    if ( input.fail() )
        return i;

    _zbior_zadan[i].set_id(i);
    
    ++i;
}
return i;
}

int problem_rpq::schrage(){

    /*
        Sortowanie zbioru zadan na podstawie czasu
        przygotowania (wartosc r). Kolejnosc malejąca.
    */
    quicksort_zbior_zadan(0, _zbior_zadan.size()-1);
    
    int t = 0;
    int k = 0;
 
    int Cmax = 0;

    while ( !(_zbior_zadan.empty()) || !(_gotowe_do_realizacji.empty()) ){

        while ( !_zbior_zadan.empty() && (_zbior_zadan.back().get_r() <= t) ){
            
            std::cout << "Przed: " << _zbior_zadan.size() << std::endl;
            std::cout << _zbior_zadan.back();

            /* Na koniec zbioru _gotowe_do_realizacji umieść zadanie o najmniejszym r */
            _gotowe_do_realizacji.push_back(std::move(_zbior_zadan.back()));

            /* Usuń ostatni element z listy */
            _zbior_zadan.pop_back();
            std::cout << "Po: " << _zbior_zadan.size() << std::endl;
        }

        if ( _gotowe_do_realizacji.empty() ){
            t = _zbior_zadan.back().get_ra();
        }
        else
        {
            quicksort_gotowe_do_realizacji(0,_gotowe_do_realizacji.size()-1);

            std::cout << "jjj" << std::endl;
            for ( int i = 0; i < _gotowe_do_realizacji.size(); ++i ){
                std::cout << _gotowe_do_realizacji[i];
            }
            std::cout << "-------" << std::endl;
            
            _gotowa_lista[k] = std::move(_gotowe_do_realizacji.back());
            _gotowe_do_realizacji.pop_back();

            t += _gotowa_lista[k].get_pa();
            Cmax = std::max(Cmax, t + _gotowa_lista[k].get_q());

            k++;
        }
    }

    return Cmax;
}

int problem_rpq::preschrage(){

    /*
        Sortowanie zbioru zadan na podstawie czasu
        przygotowania (wartosc r). Kolejnosc malejąca.
    */
    quicksort_zbior_zadan(0, _zbior_zadan.size()-1);
    
    int t = 0;
    int k = 0;

    zadanie zadanie_l ( 0, 0, 100000 );

    int Cmax = 0;

    for ( int i = 0; i < _zbior_zadan.size(); ++i ){
        std::cout << _zbior_zadan[i];
    }

    while ( !(_zbior_zadan.empty()) || !(_gotowe_do_realizacji.empty()) ){

        std::cout << "Czas: " << t << std::endl;

        while ( !_zbior_zadan.empty() && (_zbior_zadan.back().get_r() <= t) ){
            
            /* Na koniec zbioru _gotowe_do_realizacji umieść zadanie o najmniejszym r */
            _gotowe_do_realizacji.push_back(std::move(_zbior_zadan.back()));

            /* Usuń ostatni element z listy */
            _zbior_zadan.pop_back();

            if (_gotowe_do_realizacji.back().get_q() > zadanie_l.get_q() ){
       
                zadanie_l.set_p(t - _gotowe_do_realizacji.back().get_r());
                t = _gotowe_do_realizacji.back().get_ra();

                if ( zadanie_l.get_p() > 0 ){
                    _gotowe_do_realizacji.push_back(std::move(zadanie_l));
                }
            }
        }

        if ( _gotowe_do_realizacji.empty() ){
            t = _zbior_zadan.back().get_ra();
        }
        else
        {
            quicksort_gotowe_do_realizacji(0,_gotowe_do_realizacji.size()-1);

            zadanie_l = std::move(_gotowe_do_realizacji.back());
            _gotowe_do_realizacji.pop_back();

            t = t + zadanie_l.get_pa();
            
            Cmax = std::max(Cmax, t + zadanie_l.get_q());

            k++;
        }
    }

    return Cmax;
}

void problem_rpq::print(){

    for ( int i = 0; i < _size; ++i ){
        std::cout << _zbior_zadan[i];
    }
}
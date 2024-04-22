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

    std::cout << "kk" << std::endl;
 
    // partitioning the array
    int p = partition_zbior_zadan(start, end);

     std::cout << "kk2" << std::endl;
 
    // Sorting the left part
    quicksort_zbior_zadan(start, p - 1);

         std::cout << "kk3" << std::endl;
 
    // Sorting the right part
    quicksort_zbior_zadan(p + 1, end);

         std::cout << "kk4" << std::endl;
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

int problem_rpq::schrage( std::vector<zadanie> &gotowa_lista ){

    /*
        Sortowanie zbioru zadan na podstawie czasu
        przygotowania (wartosc r). Kolejnosc malejąca.
    */

   /* tutaj !!!! */
    quicksort_zbior_zadan(0, _zbior_zadan.size()-1); 
    
    int t = 0;
    int k = 0;

    int zbior_zadan_index = _zbior_zadan.size()-1;
 
    int Cmax = 0;

    while ( (zbior_zadan_index >= 0) || !(_gotowe_do_realizacji.empty()) ){

        while ( (zbior_zadan_index >=0) && (_zbior_zadan[zbior_zadan_index].get_r() <= t) ){

            /* Na koniec zbioru _gotowe_do_realizacji umieść zadanie o najmniejszym r */
            _gotowe_do_realizacji.push_back(_zbior_zadan[zbior_zadan_index]);

            /* Usuń ostatni element z listy */
            zbior_zadan_index--;

        }

        if ( _gotowe_do_realizacji.empty() ){
            t = _zbior_zadan[zbior_zadan_index].get_ra();
        }
        else
        {

            quicksort_gotowe_do_realizacji(0,_gotowe_do_realizacji.size()-1);            
             
            gotowa_lista[k] = std::move(_gotowe_do_realizacji.back());

            _gotowe_do_realizacji.pop_back();

            t += gotowa_lista[k].get_pa();
            gotowa_lista[k].set_t(t);

            Cmax = std::max(Cmax, t + gotowa_lista[k].get_q());

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

    int zbior_zadan_index = _zbior_zadan.size()-1;

    int Cmax = 0;

    while ( (zbior_zadan_index>=0) || !(_gotowe_do_realizacji.empty()) ){

        while ( (zbior_zadan_index>=0) && _zbior_zadan[zbior_zadan_index].get_r() <= t){
            
            /* Na koniec zbioru _gotowe_do_realizacji umieść zadanie o najmniejszym r */
            _gotowe_do_realizacji.push_back(_zbior_zadan[zbior_zadan_index]);

            zbior_zadan_index--;

            if (_gotowe_do_realizacji.back().get_q() > zadanie_l.get_q() ){
       
                zadanie_l.set_p(t - _gotowe_do_realizacji.back().get_r());
                t = _gotowe_do_realizacji.back().get_ra();

                if ( zadanie_l.get_p() > 0 ){
                    _gotowe_do_realizacji.push_back(std::move(zadanie_l));
                }
            }
        }

        if ( _gotowe_do_realizacji.empty() ){
            t = _zbior_zadan[zbior_zadan_index].get_ra();
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

int problem_rpq::find_minimum_r(int begin, int end, std::vector<zadanie> &permutacja ){

    /* Assign first element from vector to min_r */
    int min_r = permutacja[begin].get_r();
    int min_index = begin;

    for ( int i = begin+1; i <= end; ++i ){
        
        if ( permutacja[i].get_r() < min_r ){
            
            min_r = permutacja[i].get_r();
            min_index = i;
        }
    }

    return min_index;
}

int problem_rpq::find_minimum_q(int begin, int end, std::vector<zadanie> &permutacja ){

    /* Assign first element from vector to min_r */
    int min_q = permutacja[begin].get_q();
    int min_index = begin;

    for ( int i = begin+1; i <= end; ++i ){
        
        if ( permutacja[i].get_q() < min_q ){
            
            min_q = permutacja[i].get_q();
            min_index = i;
        }
    }

    return min_index;
}

int problem_rpq::wylicz_koniec ( int end, std::vector<zadanie> &permutacja ){

}

int problem_rpq::wyznacz_b ( int Cmax, std::vector<zadanie> &permutacja ){

    int i = permutacja.size() - 1;

    while ( Cmax != 
        permutacja[i].get_t() + permutacja[i].get_q() ){
            --i;
        }

    return i;
}

 int problem_rpq::suma_p ( int begin, int end, std::vector<zadanie> &permutacja ){

    int sum = 0;

    for ( int i = begin; i < end; ++i ){
        sum += permutacja[i].get_p();
    }

    return sum;
 }

int problem_rpq::wyznacz_a ( int c, int b, std::vector<zadanie> &permutacja ) {

    for ( int i = 0; i < b; ++i ){

        if ( c == 
            permutacja[i].get_r() + suma_p(i,b,permutacja) + permutacja[b].get_q())
            {
                return i;
            }
    }

    return 0;
}

int problem_rpq::wyznacz_c ( int a, int b, std::vector<zadanie> &permutacja ){


    for ( int i = b-1; i > a; --i ){

        if (permutacja[i].get_q() < permutacja[b].get_q()){
            return i;
        }
    }

    return 0;
}

std::vector<zadanie>& problem_rpq::carlier( int UB, std::vector<zadanie> &permutacja ){

    int U = schrage(permutacja);


    if ( U < UB ){
        UB = U;
        _gotowa_lista = permutacja;
    }


    int b = wyznacz_b(U,permutacja);
    int a = wyznacz_a(U,b,permutacja);
    int c = wyznacz_c(a,b,permutacja);

    if ( !c ){
        return _gotowa_lista;
    }

    int r_prim = find_minimum_r(c+1, b, permutacja);
    int q_prim = find_minimum_q(c+1, b, permutacja);
    int p_prim = suma_p(c+1, b, permutacja);

    int rpc_copy = permutacja[c].get_r();
    permutacja[c].get_r() = std::max(permutacja[c].get_r(), r_prim + p_prim);

    int LB = preschrage();

    if (LB < UB){
        carlier(UB,permutacja);
    }

    permutacja[c].get_r() = rpc_copy;

    int qpc_copy = permutacja[c].get_q();
    permutacja[c].get_q() = std::max(permutacja[c].get_q(), q_prim + p_prim);

    LB = preschrage();

    if (LB < UB){
        carlier(UB,permutacja);
    }

    permutacja[c].get_q() = qpc_copy;

    return _gotowa_lista;

}

int problem_rpq::wylicz_cmax ( std::vector<zadanie> &permutacja ){

    int max_cmax = 0;
    int temp = 0;

    for ( int i = 0; i < permutacja.size(); ++i ){

        temp = permutacja[i].get_t() + permutacja[i].get_q();

        if ( max_cmax < temp ){
            max_cmax = temp;
        }
    }

    return max_cmax;
}

int problem_rpq::carlier(){

    int UB = 100000000;
    std::vector<zadanie> permutacja = _zbior_zadan;

    carlier(UB, permutacja);

    return wylicz_cmax(permutacja);

}

void problem_rpq::print(){

    for ( int i = 0; i < _size; ++i ){
        std::cout << _zbior_zadan[i];
    }
}
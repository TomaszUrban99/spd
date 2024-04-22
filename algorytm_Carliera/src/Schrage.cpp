#include "Schrage.hh"

int Schrage::read( char *filename ){

    std::ifstream input;
    input.open(filename);
    
    if ( input.fail() ){
        std::cerr << "Failed to open" << std::endl;
        exit(3);
    }
    
    /* Read size of task list */
    input >> _size;
    
    /* Allocate list of elements */
    _listaZadan.resize(_size);

    /* Count number of read elements */
    
    int i = 0;
    
    while ( !input.eof() && i < _size ){

        input >> _listaZadan[i];

        if ( input.fail() )
            return i;

        _listaZadan[i].set_id(i);
    
        ++i;
    }
    
    return i;

}

void Schrage::print(){

    for ( int i = 0; i < _size; ++i ){
        std::cout << _listaZadan[i];
    }
}

int Schrage::partition_lista_zadan ( int start, int end ){
    
    int pivot = _listaZadan[start].get_r();
 
    int count = 0;

    for (int i = start + 1; i <= end; i++) {
        if (_listaZadan[i].get_r() >= pivot)
            count++;
    }

    // Giving pivot element its correct position
    int pivotIndex = start + count;


    std::swap(_listaZadan[pivotIndex], _listaZadan[start]);
 
    // Sorting left and right parts of the pivot element
    int i = start, j = end;
 
    while (i < pivotIndex && j > pivotIndex) {

        while (_listaZadan[i].get_r() >= pivot) {
            i++;
        }
 
        while (_listaZadan[j].get_r() < pivot) {
            j--;
        }
 
        if (i < pivotIndex && j > pivotIndex) {
            std::swap(_listaZadan[i++], _listaZadan[j--]);
        }
    }
 
    return pivotIndex;
}

int Schrage::partition_gotowe_do_realizacji ( int start, int end, std::vector<Zadanie> &doRealizacji ){
   
   int pivot = doRealizacji[start].get_q();
 
   int count = 0;
   
   for (int i = start + 1; i <= end; i++) {
       if (doRealizacji[i].get_q() <= pivot)
           count++;
   }
 
   // Giving pivot element its correct position
   int pivotIndex = start + count;
   std::swap(doRealizacji[pivotIndex], doRealizacji[start]);
 
   // Sorting left and right parts of the pivot element
   int i = start, j = end;
 
   while (i < pivotIndex && j > pivotIndex) {
 
       while (doRealizacji[i].get_q() <= pivot) {
           i++;
       }
 
       while (doRealizacji[j].get_q() > pivot) {
           j--;
       }
 
       if ((i < pivotIndex) && (j > pivotIndex)) {
           std::swap(doRealizacji[i++], doRealizacji[j--]);
       }
   }
 
   return pivotIndex;
}


/* Sortowanie malejaco na podstawie wartosci parametru r */
void Schrage::quicksort_lista_zadan( int start, int end ){
        // base case
    if (start >= end)
        return;
 
    // partitioning the array
    int p = partition_lista_zadan(start, end);

    // Sorting the left part
    quicksort_lista_zadan(start, p - 1);

 
    // Sorting the right part
    quicksort_lista_zadan(p + 1, end);

}

void Schrage::quicksort_gotowe_do_realizacji( int start, int end, std::vector<Zadanie> &doRealizacji ){

        // base case
    if (start >= end)
        return;
 
    // partitioning the array
    int p = partition_gotowe_do_realizacji(start, end, doRealizacji);
 
    // Sorting the left part
    quicksort_gotowe_do_realizacji(start, p - 1, doRealizacji);
 
    // Sorting the right part
    quicksort_gotowe_do_realizacji(p + 1, end, doRealizacji);
}

int Schrage::schrage(std::vector<Zadanie> &gotowaLista){

    /*
        Sortowanie zbioru zadan na podstawie czasu
        przygotowania (wartosc r). Kolejnosc malejąca.
    */

   std::vector<Zadanie> gotoweDoRealizacji;
   gotoweDoRealizacji.reserve(_listaZadan.size());

    quicksort_lista_zadan(0, _listaZadan.size()-1); 
    
    int t = 0;
    int k = 0;

    int lista_zadan_index = _listaZadan.size()-1;
 
    int Cmax = 0;

    while ( (lista_zadan_index >= 0) || !(gotoweDoRealizacji.empty()) ){

        while ( (lista_zadan_index >=0) && (_listaZadan[lista_zadan_index].get_r() <= t) ){

            /* Na koniec zbioru _gotowe_do_realizacji umieść zadanie o najmniejszym r */
            gotoweDoRealizacji.push_back(_listaZadan[lista_zadan_index]);

            /* Usuń ostatni element z listy */
            lista_zadan_index--;

        }

        if ( gotoweDoRealizacji.empty() ){
            t = _listaZadan[lista_zadan_index].get_r_const();
        }
        else
        {

            quicksort_gotowe_do_realizacji(0,gotoweDoRealizacji.size()-1, gotoweDoRealizacji);            
             
            gotowaLista[k] = std::move(gotoweDoRealizacji.back());

            gotoweDoRealizacji.pop_back();

            t += gotowaLista[k].get_p_const();
            gotowaLista[k].set_t(t);

            Cmax = std::max(Cmax, t + gotowaLista[k].get_q_const());

            k++;
        }
    }

    return Cmax;
}
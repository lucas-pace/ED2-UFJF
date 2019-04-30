 #ifndef _InsertionSort_H_
 #define _InsertionSort_H_
 
#include <iostream>
#include <stdlib.h>

#include "Registro.h";

using namespace std;

class InsertionSort
{
    public: 
        void insertionSortObject(Registro vet[], int TAM);
        void insertionSort(int vet[], int TAM);
};
#endif
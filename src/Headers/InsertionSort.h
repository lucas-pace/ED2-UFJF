 #ifndef _InsertionSort_H_
 #define _InsertionSort_H_

#include <iostream>
#include <stdlib.h>

#include "Registro.h";

using namespace std;

class InsertionSort
{
    public:
        int numComparacoes = 0;
        int numCopias = 0;
        void insertionSortObject(Registro vet[], int TAM);
        void insertionSortHibrido(Registro vet[], int inicio, int fim);
        void insertionSort(int vet[], int TAM);
};
#endif

#ifndef _SELECTIONSORT_H_
#define _SELECTIONSORT_H_

#include <iostream>
#include <stdlib.h>

#include "Registro.h"

using namespace std;

class SelectionSort
{
    public:
        void selectionSort(int vet[], int TAM);
        void selectionSortObject(Registro registros[], int TAM);
};

#endif
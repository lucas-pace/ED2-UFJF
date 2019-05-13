#ifndef _BUBBLESORT_H_
#define _BUBBLESORT_H_
 
#include <iostream>
#include <stdlib.h>

#include "../Headers/Registro.h";

using namespace std;

class BubbleSort
{
    public:
        int numComparacoes = 0;
        int numCopias = 0;
        void bubbleSort(int vet[], int TAM);
        void bubbleSortObject(Registro vet[], int TAM);
};
#endif
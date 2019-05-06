#ifndef _QUICKSORT_H_
#define _QUICKSORT_H_

#include <iostream>
#include <stdlib.h>

#include "../Headers/Registro.h";

using namespace std;

class QuickSort
{
    public:
        void quickSort(int arr[], int low, int high);
        void quickSortObject(Registro arr[], int low, int high);
        void quickSortMediana(Registro arr[], int inicio, int fim);
        void swapObject(Registro *x, Registro *y);

    private:
        int partition(int arr[], int low, int high);
        int partitionObject(Registro arr[], int low, int high);
        int partitionMediana(Registro arr[], int inicio, int fim);
};

#endif

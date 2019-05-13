#ifndef _QUICKSORT_H_
#define _QUICKSORT_H_

#include <iostream>
#include <stdlib.h>

#include "../Headers/Registro.h";

using namespace std;

class QuickSort
{
    public:
        int numComparacoes = 0;
        int numCopias = 0;

        void inicializa();
        void quickSort(int arr[], int low, int high);
        void quickSortObject(Registro arr[], int low, int high);
        void quickSortMediana(int arr[], int inicio, int fim, int k);
        int mediana(int arr[], int inicio, int fim, int k);
        void quickSortInsercao(int arr[], int inicio, int fim, int m);
        void swapObject(Registro *x, Registro *y);
        

    private:
        int partition(int arr[], int low, int high);
        int partitionObject(Registro arr[], int low, int high);
        int partitionMediana(int arr[], int inicio, int fim, int mediana);
        int partitionInsercao(int arr[], int inicio, int fim);
};

#endif

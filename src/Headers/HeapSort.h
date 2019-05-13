 #ifndef _HEAPSORT_H_
 #define _HEAPSORT_H_
 
#include <iostream>
#include <stdlib.h>

#include "Registro.h";

using namespace std;

class HeapSort
{
    public:
        int numComparacoes = 0;
        int numCopias = 0;
        void heapSort(int arr[], int n);
        void heapSortObject(Registro arr[], int n);

    private: 
        void heapify(int arr[], int n, int i);
        void heapifyObject(Registro arr[], int n, int i);
};
#endif
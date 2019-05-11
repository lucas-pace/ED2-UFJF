 #ifndef _MERGESORT_H_
 #define _MERGESORT_H_
 
#include <iostream>
#include <stdlib.h>

#include "../Headers/Registro.h";

using namespace std;

class MergeSort
{
    public: 
        MergeSort();
        void mergeSort(int vet[], int indiceEsq, int indiceDir);
        void mergeSortObject(Registro registros[], int indiceEsq, int indiceDir);

    private: 
        void Intercalacao(int vet[], int indiceEsq, int indiceMed, int indiceDir);
        void IntercalacaoObject(Registro registros[], int indiceEsq, int indiceMed, int indiceDir);
};
#endif
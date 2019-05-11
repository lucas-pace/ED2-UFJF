#include <iostream>
#include <random>
#include <stdlib.h>
#include <math.h>
#include <bits/stdc++.h>

#include "src/Headers/Registro.h";
#include "src/Headers/MergeSort.h";
#include "src/Headers/QuickSort.h";
#include "src/Headers/BubbleSort.h";
#include "src/Headers/SelectionSort.h";
#include "src/Headers/InsertionSort.h";
#include "src/Headers/HeapSort.h";


using namespace std;

class Startup
{
    public:
        void StartMergeSort(Registro registros[], int vet[], int indiceEsq, int indiceDir, ofstream &saida);
        void StartQuickSort(Registro registros[], int arr[], int low, int high, ofstream &saida);
        void StartBubbleSort(Registro registros[], int vet[], int TAM, ofstream &saida);
        void StartSelectionSort(Registro registros[], int vet[], int TAM, ofstream &saida);
        void StartInsertionSort(Registro registros[], int ids[], int TAM, ofstream &saida);
        void StartHeapSort(Registro registros[], int ids[], int TAM, ofstream &saida);

    private:
        void PrintObj(const char *nome, int TAM, ofstream &saida, long long tempo, int comparacoes, int copias);
        void PrintInt(const char *nome, int TAM, ofstream &saida, long long tempo, int comparacoes, int copias);
};

#include <iostream>
#include <random>
#include <stdlib.h>

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
        void StartMergeSort(int vet[], int indiceEsq, int indiceDir);
        void StartQuickSort(int arr[], int low, int high);
        void StartBubbleSort(int vet[], int TAM);
        void StartSelectionSort(int vet[], int TAM);
        void StartInsertionSort(Registro registros[], int ids[], int TAM);
        void StartHeapSort(Registro registros[], int ids[], int TAM);
};
#include <iostream>
#include <random>
#include <stdlib.h>

#include "src/Headers/MergeSort.h";
#include "src/Headers/QuickSort.h";
#include "src/Headers/BubbleSort.h";
#include "src/Headers/SelectionSort.h";

using namespace std;

class Startup
{
    public:
        void StartMergeSort(int vet[], int indiceEsq, int indiceDir);
        void StartQuickSort(int arr[], int low, int high);
        void StartBubbleSort(int vet[], int TAM);
        void StartSelectionSort(int vet[], int TAM);
};
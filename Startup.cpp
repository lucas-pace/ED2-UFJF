#include "Startup.h";

void Startup::StartMergeSort(int vet[], int indiceEsq, int indiceDir)
{
   MergeSort merge;
   merge.mergeSort(vet, indiceEsq, indiceDir);
}

void Startup::StartQuickSort(int vet[], int low, int high)
{
   QuickSort quick;
   quick.quickSort(vet, low, high);
}

void Startup::StartBubbleSort(int vet[], int TAM)
{
   BubbleSort bubble;
   bubble.bubbleSort(vet, TAM);
}

void Startup::StartSelectionSort(int vet[], int TAM)
{
   SelectionSort selection;
   selection.selectionSort(vet, TAM);
}
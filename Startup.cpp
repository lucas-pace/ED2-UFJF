#include "Startup.h";

#include "src/Headers/MergeSort.h";
#include "src/Headers/QuickSort.h";
#include "src/Headers/BubbleSort.h";

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
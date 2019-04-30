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

void Startup::StartInsertionSort(Registro registros[], int ids[], int TAM)
{
   InsertionSort insertion;
   
   cout << "Insertion Sort com Ids" << endl;
   insertion.insertionSort(ids, TAM);

   cout << "Insertion Sort com Registros" << endl;
   insertion.insertionSortObject(registros, TAM);
}

void Startup::StartHeapSort(Registro registros[], int ids[], int TAM)
{
   HeapSort heap;
   
   cout << "Insertion Sort com Ids" << endl;
   heap.heapSort(ids, TAM);

   cout << "Insertion Sort com Registros" << endl;
   heap.heapSortObject(registros, TAM);
}
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

   {
      auto start = chrono::steady_clock::now();
      insertion.insertionSort(ids, TAM);
      auto end = chrono::steady_clock::now();

      PrintInt(ids, TAM);
      printime(end - start);
   }

   {
      auto start = chrono::steady_clock::now();
      insertion.insertionSortObject(registros, TAM);
      auto end = chrono::steady_clock::now();

      PrintObj(registros, TAM);
      printime(end - start);
   }
}

void Startup::StartHeapSort(Registro registros[], int ids[], int TAM)
{
   HeapSort heap;

   cout << "Insertion Sort com Ids" << endl;
   heap.heapSort(ids, TAM);

   cout << "Insertion Sort com Registros" << endl;
   heap.heapSortObject(registros, TAM);
}

void Startup::PrintInt(int arr[], int TAM)
{
   cout << "Insertion Sort com Ids"
        << ": ";

   for (int j = 0; j < TAM; j++)
   {
      cout << arr[j] << " ";
   }

   cout << endl;
}

void Startup::PrintObj(Registro arr[], int TAM)
{
   cout << "Insertion Sort com Registros"
        << ": ";

   for (int j = 0; j < TAM; j++)
   {
      cout << arr[j].getUserId() << " ";
   }

   cout << endl;
}
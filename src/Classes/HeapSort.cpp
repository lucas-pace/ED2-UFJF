#include "../Headers/HeapSort.h";

void HeapSort::heapSort(int arr[], int n) 
{ 
    for (int i = n / 2 - 1; i >= 0; i--) 
        heapify(arr, n, i); 
  
    for (int i=n-1; i>=0; i--) 
    { 
        swap(arr[0], arr[i]); 
        heapify(arr, i, 0); 
    } 
}

void HeapSort::heapify(int arr[], int n, int i) 
{ 
    int maior = i; 
    int l = 2*i + 1;
    int r = 2*i + 2; 
  
    if (l < n && arr[l] > arr[maior]) 
        maior = l; 
  
    if (r < n && arr[r] > arr[maior]) 
        maior = r; 
  
    if (maior != i) 
    { 
        swap(arr[i], arr[maior]); 
        heapify(arr, n, maior); 
    } 
} 
  
void HeapSort::heapSortObject(Registro arr[], int n) 
{ 
    for (int i = n / 2 - 1; i >= 0; i--) 
        heapifyObject(arr, n, i); 
  
    for (int i=n-1; i>=0; i--) 
    { 
        swap(arr[0], arr[i]); 
        heapifyObject(arr, i, 0); 
    } 
}

void HeapSort::heapifyObject(Registro arr[], int n, int i) 
{ 
    int maior = i; 
    int l = 2*i + 1;
    int r = 2*i + 2; 
  
    if (l < n && arr[l].getUserId() > arr[maior].getUserId()) 
        maior = l; 
  
    if (r < n && arr[r].getUserId() > arr[maior].getUserId()) 
        maior = r; 
  
    if (maior != i) 
    { 
        swap(arr[i], arr[maior]); 
        heapifyObject(arr, n, maior); 
    } 
} 
  

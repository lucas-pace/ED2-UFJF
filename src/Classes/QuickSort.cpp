#include "../Headers/QuickSort.h";

int QuickSort::partition(int arr[], int low, int high) 
{ 
    int pivot = arr[high];
    int i = (low - 1); 
  
    for (int j = low; j <= high- 1; j++) 
    { 
        if (arr[j] <= pivot) 
        { 
            i++;
            swap(arr[i], arr[j]); 
        } 
    } 

    swap(arr[i + 1], arr[high]); 
    return (i + 1); 
} 
  
void QuickSort::quickSort(int arr[], int low, int high) 
{ 
    if (low < high) 
    { 
        int pi = partition(arr, low, high); 

        quickSort(arr, low, pi - 1); 
        quickSort(arr, pi + 1, high); 
    } 
}

void swap(int *x, int *y)
{
    int aux = *x;
    *x = *y;
    *y = aux;
}
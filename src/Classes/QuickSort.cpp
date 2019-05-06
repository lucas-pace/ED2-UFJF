#include "../Headers/QuickSort.h";

int numComparacoes = 0;

void QuickSort::quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

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

void QuickSort::quickSortObject(Registro arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partitionObject(arr, low, high);

        quickSortObject(arr, low, pi - 1);
        quickSortObject(arr, pi + 1, high);
    }
}

int QuickSort::partitionObject(Registro arr[], int low, int high)
{
    int pivot = arr[high].getUserId();
    int i = (low - 1);

    for (int j = low; j <= high- 1; j++)
    {
        if (arr[j].getUserId() <= pivot)
        {
            i++;
            numComparacoes++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);

    return (i + 1);
}

void QuickSort::swapObject(Registro *x, Registro *y)
{
    Registro aux = *x;
    *x = *y;
    *y = aux;
}

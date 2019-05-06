#include "../Headers/QuickSort.h";

int numComparacoes = 0;
int numCopias = 0;

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
    numCopias++;
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

void QuickSort::quickSortMedian(Registro arr[], int low, int high)
{
    if (low < high) {
        //realiza a partição
        int q = partitionMedian(arr, low, high);
        //ordena a partição esquerda
        quickSortMedian(arr, low, q - 1);
        //ordena a partição direita
        quickSortMedian(arr, q + 1, high);
    }
}

int QuickSort::partitionMedian(Registro arr[], int low, int high)
{
    //procura a mediana entre os valores dados
    int middle = (low + high) / 2;
    int a = arr[low].getUserId();
    int b = arr[middle].getUserId();
    int c = arr[high].getUserId();
    int medianIndex; //índice da mediana
    //A sequência de if...else a seguir verifica qual é a mediana entre os 3 números
    if (a < b) {
        if (b < c) {
            medianIndex = middle;
        } else {
            if (a < c) {
                medianIndex = high;
            } else {
                medianIndex = low;
            }
        }
    } else {
        if (c < b) {
            medianIndex = middle;
        } else {
            if (c < a) {
                medianIndex = high;
            } else {
                medianIndex = low;
            }
        }
    }
    //coloca o elemento da mediana no fim para poder usar o Quicksort recursivo normal
    swap(arr[medianIndex], arr[high]);

    //*******************ALGORITMO DE PARTIÇÃO*********************
    int pivot = arr[high].getUserId();
    int i = low - 1;
    int j;
    /*
     * Este laço irá varrer os vetores da esquerda para direira
     * procurando os elementos que são menores ou iguais ao pivô.
     * Esses elementos são colocados na partição esquerda.
     */
    for (j = low; j <= high - 1; j++) {
        if (arr[j].getUserId() <= pivot) {
            i++;
            numComparacoes++;
            swap(arr[i], arr[j]);
        }
    }
    //coloca o pivô na posição de ordenação
    swap(arr[i + 1], arr[high]);
    return i + 1; //retorna a posição do pivô
}

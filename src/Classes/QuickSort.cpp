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
        //realiza a parti��o
        int q = partitionMedian(arr, low, high);
        //ordena a parti��o esquerda
        quickSortMedian(arr, low, q - 1);
        //ordena a parti��o direita
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
    int medianIndex; //�ndice da mediana
    //A sequ�ncia de if...else a seguir verifica qual � a mediana entre os 3 n�meros
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

    //*******************ALGORITMO DE PARTI��O*********************
    int pivot = arr[high].getUserId();
    int i = low - 1;
    int j;
    /*
     * Este la�o ir� varrer os vetores da esquerda para direira
     * procurando os elementos que s�o menores ou iguais ao piv�.
     * Esses elementos s�o colocados na parti��o esquerda.
     */
    for (j = low; j <= high - 1; j++) {
        if (arr[j].getUserId() <= pivot) {
            i++;
            numComparacoes++;
            swap(arr[i], arr[j]);
        }
    }
    //coloca o piv� na posi��o de ordena��o
    swap(arr[i + 1], arr[high]);
    return i + 1; //retorna a posi��o do piv�
}

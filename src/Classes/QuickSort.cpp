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
    int pivo = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high- 1; j++)
    {
        if (arr[j] <= pivo)
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
    int pivo = arr[high].getUserId();
    numCopias++;
    int i = (low - 1);

    for (int j = low; j <= high- 1; j++)
    {
        if (arr[j].getUserId() <= pivo)
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

void QuickSort::quickSortMediana(Registro arr[], int inicio, int fim)
{
    if (inicio < fim) {
        //realiza a parti��o
        int q = partitionMediana(arr, inicio, fim);
        //ordena a parti��o esquerda
        quickSortMediana(arr, inicio, q - 1);
        //ordena a parti��o direita
        quickSortMediana(arr, q + 1, fim);
    }
}

int QuickSort::partitionMediana(Registro arr[], int inicio, int fim)
{
    //procura a mediana entre os valores dados
    int meio = (inicio + fim) / 2;
    int a = arr[inicio].getUserId();
    int b = arr[meio].getUserId();
    int c = arr[fim].getUserId();
    int mediana; //�ndice da mediana
    //A sequ�ncia de if...else a seguir verifica qual � a mediana entre os 3 n�meros
    if (a < b) {
        if (b < c) {
            mediana = meio;
        } else {
            if (a < c) {
                mediana = fim;
            } else {
                mediana = inicio;
            }
        }
    } else {
        if (c < b) {
            mediana = meio;
        } else {
            if (c < a) {
                mediana = fim;
            } else {
                mediana = inicio;
            }
        }
    }
    //coloca o elemento da mediana no fim para poder usar o Quicksort recursivo normal
    swap(arr[mediana], arr[fim]);

    //*******************ALGORITMO DE PARTI��O*********************
    int pivo = arr[fim].getUserId();
    int i = inicio - 1;
    int j;
    /*
     * Este la�o ir� varrer os vetores da esquerda para direira
     * procurando os elementos que s�o menores ou iguais ao piv�.
     * Esses elementos s�o colocados na parti��o esquerda.
     */
    for (j = inicio; j <= fim - 1; j++) {
        if (arr[j].getUserId() <= pivo) {
            i++;
            numComparacoes++;
            swap(arr[i], arr[j]);
        }
    }
    //coloca o piv� na posi��o de ordena��o
    swap(arr[i + 1], arr[fim]);
    return i + 1; //retorna a posi��o do piv�
}

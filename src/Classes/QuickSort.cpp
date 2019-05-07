#include "../Headers/QuickSort.h";
#include "../Headers/InsertionSort.h";

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

void QuickSort::quickSortMediana(Registro arr[], int inicio, int fim, int k)
{
    if (inicio < fim)
    {
        int q = partitionMediana(arr, inicio, fim, mediana(arr, inicio, fim, k));
        quickSortMediana(arr, inicio, q - 1, k);
        quickSortMediana(arr, q + 1, fim, k);
    }
}

int QuickSort::mediana(Registro arr[], int inicio, int fim, int k)
{
    InsertionSort is = InsertionSort();
    int indiceMediana;
	int indiceRand;

    Registro vetor[k];
    for (int i = 0; i < k; i++)
    {
        srand(i);
        indiceRand = rand() % (fim - inicio);
        vetor[i] = arr[indiceRand];
    }

    is.insertionSortHibrido(vetor, 0, k);
    indiceMediana = vetor[k == 3 ? 1 : 2].getMovieId();
    return indiceMediana;
}

int QuickSort::partitionMediana(Registro arr[], int inicio, int fim,int mediana)
{
    int pospiv = inicio + (mediana % (fim - inicio + 1));
    int pivo = arr[pospiv].getUserId(); //Pega o userID da posicao que foi pedida e coloca ela como pivo
	swap(arr[pospiv], arr[fim]);
	pospiv = fim;
    int i = inicio - 1;
    int j;
    for (j = inicio; j <= fim - 1; j++) {
        if (arr[j].getUserId() <= pivo) {
            i++;
            numComparacoes++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[fim]);
    return i + 1;
}

void QuickSort::quickSortInsercao(Registro arr[], int inicio, int fim, int m)
{
    InsertionSort is = InsertionSort();
        if (inicio < fim)
		{
		    if(m = 10)
            {
                if (fim - inicio <= 10)
                {
				is.insertionSortHibrido(arr, inicio, fim + 1);
                }
                else
                {
				int part = partitionObject(arr, inicio, fim);
				quickSortInsercao(arr, inicio, part - 1, 10);
				quickSortInsercao(arr, part + 1, fim, 10);
                }
            }
            else
            {
                if (fim - inicio <= 100)
                {
				is.insertionSortHibrido(arr, inicio, fim + 1);
                }
                else
                {
				int part = partitionObject(arr, inicio, fim);
				quickSortInsercao(arr, inicio, part - 1, 100);
				quickSortInsercao(arr, part + 1, fim, 100);
                }
            }
		}
}

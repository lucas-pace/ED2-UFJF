#include "../Headers/QuickSort.h";
#include "../Headers/InsertionSort.h";
int numComparacoes = 0;
    int numCopias = 0;
/**
 * Utiliza o algortimo de Quick Sort recursivo para ordenar um dado array de inteiros
 *
 * @param int arr[]
 * @param int low
 * @param int high
 * @return void
// **/

void QuickSort::quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

/**
 * Algortimo de particionamento do m�todo de quick sort recursivo
 *
 * @param int arr[]
 * @param int low
 * @param int high
 * @return int
*/
int QuickSort::partition(int arr[], int low, int high)
{
    int pivo = arr[high];
    numCopias++;

    int i = (low - 1);

    for (int j = low; j <= high - 1; j++)
    {
        numComparacoes++;
        if (arr[j] <= pivo)
        {
            i++;
            swap(arr[i], arr[j]);
            numCopias+=3;
        }
    }

    swap(arr[i + 1], arr[high]);
    numCopias+=3;
    
    return (i + 1);
}

/**
 * Utiliza o algortimo de Quick Sort recursivo para ordenar um dado array de Registros
 *
 * @param Registro arr[]
 * @param int low
 * @param int high
 * @return void
*/
void QuickSort::quickSortObject(Registro arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partitionObject(arr, low, high);

        quickSortObject(arr, low, pi - 1);
        quickSortObject(arr, pi + 1, high);
    }
}

/**
 * Algortimo de particionamento do m�todo de quick sort recursivo para objetos
 *
 * @param Registro arr[]
 * @param int low
 * @param int high
 * @return int
*/
int QuickSort::partitionObject(Registro arr[], int low, int high)
{
    int pivo = arr[high].getUserId();
    numCopias++;

    int i = (low - 1);

    for (int j = low; j <= high- 1; j++)
    {
        numComparacoes++;
        if (arr[j].getUserId() <= pivo)
        {
            i++;
            swap(arr[i], arr[j]);
            numCopias+=3;
        }
    }

    swap(arr[i + 1], arr[high]);
    numCopias+=3;

    return (i + 1);
}

void QuickSort::quickSortMediana(int arr[], int inicio, int fim, int k)
{
    if (inicio < fim)
    {
        int q = partitionMediana(arr, inicio, fim, mediana(arr, inicio, fim, k));
        quickSortMediana(arr, inicio, q - 1, k);
        quickSortMediana(arr, q + 1, fim, k);
    }
}

/**
 * Fun��o que encontra a mediana, dado um array de Registros.
 *
 * @param Registro arr[]
 * @param int inicio
 * @param int fim
 * @param int k
 * @return int
*/
int QuickSort::mediana(int arr[], int inicio, int fim, int k)
{
    InsertionSort is = InsertionSort();
    int indiceMediana;
	int indiceRand;

    int vetor[k];
    for (int i = 0; i < k; i++)
    {
        srand(i);
        indiceRand = rand() % (fim - inicio);
        vetor[i] = arr[indiceRand];
        numCopias++;
    }

    is.insertionSortHibrido(vetor, 0, k);
    indiceMediana = vetor[k == 3 ? 1 : 2];
    return indiceMediana;
}

/**
 * Algortimo de particionamento do quick sort recursivo
 * que utiliza a mediana de n�meros aleat�rios como pivo.
 *
 * @param Registro arr[]
 * @param int inicio
 * @param int fim
 * @param int mediana
 * @return int
*/
int QuickSort::partitionMediana(int arr[], int inicio, int fim,int mediana)
{
    int pospiv = inicio + (mediana % (fim - inicio + 1));
    int pivo = arr[pospiv]; //Pega o userID da posicao que foi pedida e coloca ela como pivo
    numCopias++;

	swap(arr[pospiv], arr[fim]);
    numCopias+=3;

	pospiv = fim;
    int i = inicio - 1;
    int j;
    for (j = inicio; j <= fim - 1; j++) {
        numComparacoes++;
        if (arr[j]<= pivo) {
            i++;
            swap(arr[i], arr[j]);
            numCopias+=3;
        }
    }
    swap(arr[i + 1], arr[fim]);
    numCopias+=3;

    return i + 1;
}

/**
 * Algortimo de Quick Sort Hibrido que utiliza o Insert Sort
 * para ordenar valores de pequenas parti��es.
 *
 * @param Registro arr[]
 * @param int inicio
 * @param int fim
 * @param int m
 * @return int
*/
void QuickSort::quickSortInsercao(int arr[], int inicio, int fim, int m)
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
				int part = partition(arr, inicio, fim);
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
				int part = partition(arr, inicio, fim);
				quickSortInsercao(arr, inicio, part - 1, 100);
				quickSortInsercao(arr, part + 1, fim, 100);
                }
            }
		}
}

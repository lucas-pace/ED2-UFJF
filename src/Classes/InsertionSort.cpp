#include "../Headers/InsertionSort.h";

void InsertionSort::insertionSortObject(Registro vet[], int TAM)
{
    for (int i = 1; i <= TAM; i++)
    {
        int valorAtual = vet[i].getUserId();
        
        for (int j = i - 1; j != 0 && vet[j - 1].getUserId() > vet[j].getUserId(); j--)
        {
            numCopias;
            swap(vet[j], vet[j - 1]);
        }
        numComparacoes++;
    }
}

void InsertionSort::insertionSort(int vet[], int TAM)
{
    for (int i = 1; i <= TAM; i++)
    {
        int valorAtual = vet[i];
        
        for (int j = i - 1; j != 0 && vet[j - 1] > vet[j]; j--)
        {    
            swap(vet[j], vet[j - 1]);
            numCopias++;
        }
        numComparacoes++;
    }
}

void InsertionSort::insertionSortHibrido(Registro arr[], int inicio, int fim)
{
    int i, j;
	Registro chave;

	for (i = inicio + 1; i < fim; i++)
	{
		chave = arr[i];
		j = i - 1;

		while (j >= 0 && (arr[j].getUserId() > chave.getUserId()))
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = chave;
	}
}

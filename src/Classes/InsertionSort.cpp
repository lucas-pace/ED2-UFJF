#include "../Headers/InsertionSort.h";

void InsertionSort::insertionSortObject(Registro vet[], int TAM)
{
    for (int i = 1; i <= TAM; i++)
    {
        int valorAtual = vet[i].getUserId();
        for (int j = i - 1; j != 0 && vet[j - 1].getUserId() > vet[j].getUserId(); j--)
        {
            swap(vet[j], vet[j - 1]);
        }
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
        }
    }
}
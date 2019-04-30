#include "../Headers/SelectionSort.h";

void SelectionSort::selectionSort(int vet[], int TAM)
{
    int menor, idMenor;
    for (int i = 0; i < TAM; i++)
    {
        idMenor = i;
        for (int j = i; j < TAM; j++)
        {
            if (vet[idMenor] > vet[j])
            {
                idMenor = j;
            }
        }
        swap(vet[idMenor], vet[i]);
    }
}
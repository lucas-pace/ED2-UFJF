#include "../Headers/BubbleSort.h";

void BubbleSort::bubbleSort(int vet[], int TAM)
{
    int aux;
    for (int i = 0; i < TAM; i++)
    {
        for (int j = 0; j < TAM - 1; j++)
        {
            if (vet[j] > vet[j + 1])
            {
                swap(vet[j], vet[j + 1]);
            }
        }
    }
}
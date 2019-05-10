#include "../Headers/BubbleSort.h";

/**
 * Utiliza o algortimo de Bubble Sort para ordenar um dado array de inteiros
 *
 * @param int vet[]
 * @param int TAM
 * @return void
*/
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

/**
 * Utiliza o algortimo de Bubble Sort para ordenar um dado array de registros
 *
 * @param Registro vet[]
 * @param int TAM
 * @return void
*/
void BubbleSort::bubbleSortObject(Registro vet[], int TAM)
{
    int aux;
    for (int i = 0; i < TAM; i++)
    {
        for (int j = 0; j < TAM - 1; j++)
        {
            if (vet[j].getUserId() > vet[j + 1].getUserId())
            {
                swap(vet[j], vet[j + 1]);
            }
        }
    }
}

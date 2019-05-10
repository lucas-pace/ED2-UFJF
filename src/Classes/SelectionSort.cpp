#include "../Headers/SelectionSort.h";

/**
 * Utiliza o algortimo de Selection Sort para ordenar um dado array de inteiros
 *
 * @param int vet[]
 * @param  int tam
 * @return void
*/
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

#include "../Headers/MergeSort.h";

MergeSort::MergeSort(){}

void MergeSort::mergeSort(int vet[], int indiceEsq, int indiceDir)
{
    if (indiceEsq < indiceDir)
    {
        int indiceMed = indiceEsq+(indiceDir-indiceEsq)/2;

        mergeSort(vet, indiceEsq, indiceMed);
        mergeSort(vet, indiceMed+1, indiceDir);

        Intercalacao(vet, indiceEsq, indiceMed, indiceDir);
    }
}

void MergeSort::Intercalacao(int vet[], int indiceEsq, int indiceMed, int indiceDir)
{
    int i, j, k;
    int tam1 = indiceMed - indiceEsq + 1;
    int tam2 =  indiceDir - indiceMed;

    int vetEsq[tam1], vetDir[tam2];

    for (i = 0; i < tam1; i++)
        vetEsq[i] = vet[indiceEsq + i];
    for (j = 0; j < tam2; j++)
        vetDir[j] = vet[indiceMed + 1+ j];

    i = 0;
    j = 0;
    k = indiceEsq;
    while (i < tam1 && j < tam2)
    {
        if (vetEsq[i] <= vetDir[j])
        {
            vet[k] = vetEsq[i];
            i++;
        }
        else
        {
            vet[k] = vetDir[j];
            j++;
        }
        k++;
    }

    while (i < tam1)
    {
        vet[k] = vetEsq[i];
        i++;
        k++;
    }

    while (j < tam2)
    {
        vet[k] = vetDir[j];
        j++;
        k++;
    }
}


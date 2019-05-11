#include "../Headers/MergeSort.h";

MergeSort::MergeSort(){}

/**
 * Utiliza o algortimo de Merge Sort para ordenar um vetor de inteiros
 *
 * @param int vet[]
 * @param int indiceEsq
 * @param int indiceDir
 * @return void
*/
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

/**
 * Algortimo de intercalação para o Merge Sort
 *
 * @param int vet[]
 * @param int indiceEsq
 * @param int indiceMed
 * @param int indiceDir
 * @return void
*/
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

void MergeSort::mergeSortObject(Registro registros[], int indiceEsq, int indiceDir)
{
    if (indiceEsq < indiceDir)
    {
        int indiceMed = indiceEsq+(indiceDir-indiceEsq)/2;

        mergeSortObject(registros, indiceEsq, indiceMed);
        mergeSortObject(registros, indiceMed+1, indiceDir);

        IntercalacaoObject(registros, indiceEsq, indiceMed, indiceDir);
    }
}

void MergeSort::IntercalacaoObject(Registro registros[], int indiceEsq, int indiceMed, int indiceDir)
{
    int i, j, k;
    int tam1 = indiceMed - indiceEsq + 1;
    int tam2 =  indiceDir - indiceMed;

    int vetEsq[tam1], vetDir[tam2];

    for (i = 0; i < tam1; i++)
        vetEsq[i] = registros[indiceEsq + i].getUserId();
    for (j = 0; j < tam2; j++)
        vetDir[j] = registros[indiceMed + 1+ j].getUserId();

    i = 0;
    j = 0;
    k = indiceEsq;
    while (i < tam1 && j < tam2)
    {
        if (vetEsq[i] <= vetDir[j])
        {
            registros[k].setUserId(vetEsq[i]);
            i++;
        }
        else
        {
            registros[k].setUserId(vetDir[j]);
            j++;
        }
        k++;
    }

    while (i < tam1)
    {
        registros[k].setUserId(vetEsq[i]);
        i++;
        k++;
    }

    while (j < tam2)
    {
        registros[k].setUserId(vetDir[j]);
        j++;
        k++;
    }
}


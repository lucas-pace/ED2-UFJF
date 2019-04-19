#include <iostream>
#include <random>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <bits/stdc++.h>
#include "registro.h"

using namespace std;



void printVector(int vet[], int TAM)
{
    for(int i = 0; i < TAM; i++)
        cout << vet[i] << " ";
    cout << endl;
}

void aleatoryVector(int vet[], int TAM)
{
    srand(time(NULL));
    for(int i = 0; i < TAM; i++)
    {
        vet[i] = rand() % 100;
    }
}

void insertionSort(int vet[], int TAM)
{
    for(int i = 1 ; i <= TAM; i++)
    {
        int valorAtual = vet[i];
        for(int j = i-1; j != 0 && vet[j-1] > vet[j]; j--)
        {
            swap(vet[j], vet[j-1]);
        }
    }
}

void bubbleSort(int vet[], int TAM )
{
    int aux;
    for(int i = 0; i < TAM; i++)
    {
        for(int j = 0 ; j < TAM-1; j++)
        {
            if(vet[j] > vet[j+1])
            {
                swap(vet[j],vet[j+1]);
            }
        }
    }
}


void selectionSort(int vet[], int TAM)
{
    int menor, idMenor;
    for(int i = 0 ; i < TAM; i++)
    {
        idMenor = i;
        for(int j=i; j < TAM; j++)
        {
            if(vet[idMenor] > vet[j])
            {
                idMenor = j;
            }
        }
        swap(vet[idMenor], vet[i]);
    }
}

void selectionSort(Registro vet[], int TAM)
{
    int menor, idMenor;
    for(int i = 0 ; i < TAM; i++)
    {
        idMenor = i;
        for(int j=i; j < TAM; j++)
        {
            if(vet[idMenor].getMovieId() > vet[j].getMovieId())
            {
                idMenor = j;
            }
        }
        swap(vet[idMenor], vet[i]);
    }
}

void intercalacao(int vet[], int indiceEsq, int indiceMed, int indiceDir)
{
    int i, j, k;
    int tam1 = indiceMed - indiceEsq + 1;
    int tam2 =  indiceDir - indiceMed;

    /* Vetores auxiliares */
    int vetEsq[tam1], vetDir[tam2];

    /* Preenche os vetores auxiliares */
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

    /* Copy the remaining elements of R[], if there
       are any */
    while (j < tam2)
    {
        vet[k] = vetDir[j];
        j++;
        k++;
    }
}

void mergeSort(int vet[], int indiceEsq, int indiceDir)
{
    if (indiceEsq < indiceDir)
    {
        int indiceMed = indiceEsq+(indiceDir-indiceEsq)/2;

        mergeSort(vet, indiceEsq, indiceMed);
        mergeSort(vet, indiceMed+1, indiceDir);

        intercalacao(vet, indiceEsq, indiceMed, indiceDir);
    }
}

void generateAndPrint(int vet[], int TAM)
{
    aleatoryVector(vet, TAM);
    cout << "Vetor Atual:  " << endl;
    printVector(vet, TAM);
}

void swap(int *x,int *y)
{
    int aux = *x;
    *x = *y;
    *y = aux;
}

int main()
{
    ifstream arquivo;
    arquivo.open("ratings.csv");
    srand(time(NULL));
    if(arquivo.is_open())
    {
        arquivo.seekg(0, arquivo.end); // apontar para o final do arquivo
        int tamanhoArquivo = arquivo.tellg();
        ifstream entrada;
        entrada.open("entrada.txt");
        if(entrada.is_open())
        {
            while(!entrada.eof())
            {
                string tamanho;
                getline(entrada,tamanho);
                int TAM = atoi(tamanho.c_str()); // transformando tamanho para inteiro
                Registro *registros = new Registro[TAM];
                cout << "Gerando conjuntos de "<< TAM << " Valores" << endl << "-------------------" << endl;
                for(int i = 0; i < 5; i++)  // rodar 5 vezes e gerar 5 conjuntos de elementos distintos de mesmo tamanho
                {
                    auto start = chrono::steady_clock::now();
                    for(int j = 0; j < TAM; j++)
                    {
                        registros[j] = pegarKbAleatorio(arquivo,registros[j], tamanhoArquivo);
                        cout << registros[j].getMovieId() << " ";
                    }
                    cout << endl;
                    selectionSort(registros,TAM);
                    cout << "Ordenado: " << endl;
                    for(int j = 0 ; j < TAM; j++)
                    {
                        cout << registros[j].getMovieId() << " ";
                    }
                    cout << "Tempo: ";
                    auto end = chrono::steady_clock::now();
                    auto diff = end - start;
                    cout << chrono::duration <double, milli> (diff).count() << " ms" << endl;
                    cout << endl << endl;
                }
                cout << endl << "-------------------" <<endl;
            }

        }
    }
    /*
        int *vet = new int[TAM];
        generateAndPrint(vet, TAM);

        int option = 0;
        cout << "Escolha qual algoritmo voce quer usar: " << endl;
        cout << "[1] = Selection Sort" << endl;
        cout << "[2] = Bubble Sort" << endl;
        cout << "[3] = Insertion Sort" << endl;
        cout << "[4] = Merge Sort" << endl;
        cin >> option;
        switch(option)
        {
        case 1:
            selectionSort(vet, TAM);
        case 2:
            bubbleSort(vet,TAM);
        case 3:
            insertionSort(vet, TAM);
        case 4:
            mergeSort(vet, 0, TAM);
        }

        cout << "Vetor depois de ordenar: " << endl;
        printVector(vet, TAM);
        delete []vet;
    */
    return 0;
}

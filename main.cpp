#include <iostream>
#include <random>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <bits/stdc++.h>
#include "src/Headers/Registro.h";
#include "Startup.h";

using namespace std;

void printVector(int vet[], int TAM)
{
    for (int i = 0; i < TAM; i++)
        cout << vet[i] << " ";
    cout << endl;
}

void aleatoryVector(int vet[], int TAM)
{
    srand(time(NULL));
    for (int i = 0; i < TAM; i++)
    {
        vet[i] = rand() % 100;
    }
}

void insertionSort(int vet[], int TAM)
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

void selectionSort(int vet[], int TAM)
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

void selectionSort(Registro vet[], int TAM)
{
    int menor, idMenor;
    for (int i = 0; i < TAM; i++)
    {
        idMenor = i;
        for (int j = i; j < TAM; j++)
        {
            if (vet[idMenor].getMovieId() > vet[j].getMovieId())
            {
                idMenor = j;
            }
        }
        swap(vet[idMenor], vet[i]);
    }
}

void generateAndPrint(int vet[], int TAM)
{
    aleatoryVector(vet, TAM);
    cout << "Vetor Atual:  " << endl;
    printVector(vet, TAM);
}

int main()
{
    int TAM = 10;
    int *vet = new int[TAM];

    Startup startup;

    generateAndPrint(vet, TAM);

    int option = 0;
    cout << "Escolha qual algoritmo voce quer usar: " << endl;
    cout << "[1] = Selection Sort" << endl;
    cout << "[2] = Bubble Sort" << endl;
    cout << "[3] = Insertion Sort" << endl;
    cout << "[4] = Merge Sort" << endl;
    cout << "[5] = Quick Sort" << endl;
    cin >> option;
    switch (option)
    {
    case 1:
        selectionSort(vet, TAM);
    case 2:
        startup.StartBubbleSort(vet, TAM);
    case 3:
        insertionSort(vet, TAM);
    case 4:
        startup.StartMergeSort(vet, 0, TAM);
    case 5:
        startup.StartQuickSort(vet, 0, TAM);
    }

    cout << "Vetor depois de ordenar: " << endl;
    printVector(vet, TAM);

    delete[] vet;

    return 0;
}

// void LeArquivo(string arq)
// {
//     Registro registro;

//     ifstream arquivo;
//     arquivo.open(arq);
//     srand(time(NULL));
//     if (arquivo.is_open())
//     {
//         arquivo.seekg(0, arquivo.end); // apontar para o final do arquivo
//         int tamanhoArquivo = arquivo.tellg();
//         ifstream entrada;
//         entrada.open("entrada.txt");
//         if (entrada.is_open())
//         {
//             while (!entrada.eof())
//             {
//                 string tamanho;
//                 getline(entrada, tamanho);
//                 int TAM = atoi(tamanho.c_str()); // transformando tamanho para inteiro

//                 Registro *registros = new Registro[TAM];
//                 cout << "Gerando conjuntos de " << TAM << " Valores" << endl
//                      << "-------------------" << endl;
//                 for (int i = 0; i < 5; i++) // rodar 5 vezes e gerar 5 conjuntos de elementos distintos de mesmo tamanho
//                 {
//                     auto start = chrono::steady_clock::now();
//                     for (int j = 0; j < TAM; j++)
//                     {
//                         registros[j] = registro.pegarKbAleatorio(arquivo, registros[j], tamanhoArquivo);
//                         cout << registros[j].getMovieId() << " ";
//                     }
//                     cout << endl;
//                     selectionSort(registros, TAM);
//                     cout << "Ordenado: " << endl;
//                     for (int j = 0; j < TAM; j++)
//                     {
//                         cout << registros[j].getMovieId() << " ";
//                     }
//                     cout << "Tempo: ";
//                     auto end = chrono::steady_clock::now();
//                     auto diff = end - start;
//                     cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;
//                     cout << endl
//                          << endl;
//                 }
//                 cout << endl
//                      << "-------------------" << endl;
//             }
//         }
//     }
// }
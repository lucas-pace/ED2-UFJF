#include <iostream>
#include <random>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <bits/stdc++.h>
#include "src/Headers/Registro.h";
#include "src/Headers/QuickSort.h";
#include "Startup.h";

using namespace std;

/// Variaveis do quickSort.cpp que registram as estatisticas;
extern int numComparacoes;
extern int numCopias;

void swap(int *x, int *y)
{
    int aux = *x;
    *x = *y;
    *y = aux;
}

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

void generateAndPrint(int vet[], int TAM)
{
    aleatoryVector(vet, TAM);
    cout << "Vetor Atual:  " << endl;
    printVector(vet, TAM);
}

Registro *teste(int TAM)
{
    Registro *registros = new Registro[TAM];

    for (int i = 0; i < TAM; i++)
    {
        registros[i].setUserId(rand() % 100);
        registros[i].setRating((float)rand());
        registros[i].setMovieId(rand());
    }

    return registros;
}

int tempoProcessamento()
{
    auto start = chrono::steady_clock::now();
    cout << "Tempo: ";
    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;
    cout << endl
         << endl;
}


void Menu()
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
        startup.StartSelectionSort(vet, TAM);
        break;
    case 2:
        startup.StartBubbleSort(vet, TAM);
        break;
    case 3:
        //startup.StartInsertionSort(vet, TAM);
        //break;
    case 4:
        startup.StartMergeSort(vet, 0, TAM);
        break;
    case 5:
        startup.StartQuickSort(vet, 0, TAM);
        break;
    }

    cout << "Vetor depois de ordenar: " << endl;
    printVector(vet, TAM);

    delete[] vet;
}

void LeArquivo()
{
    Startup start;
    QuickSort *q = new QuickSort();

    ifstream arquivo;
    arquivo.open("ratings.csv");

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
                    cout << "Nao ordenado" << endl;
                    auto start = chrono::steady_clock::now();
                    for(int j = 0; j < TAM; j++)
                    {
                        registros[j] = registros->pegarKbAleatorio(arquivo,registros[j], tamanhoArquivo);
                        cout << registros[j].getUserId() << " ";
                    }
                    cout << endl;
                    q->quickSortMediana(registros, 0,TAM-1);
                    cout << "Ordenado: " << endl;
                    for(int j = 0 ; j < TAM; j++)
                    {
                        cout << registros[j].getUserId() << " ";
                    }
                    cout << endl;
                    cout << "Tempo: " << endl;
                    auto end = chrono::steady_clock::now();
                    auto diff = end - start;
                    cout << chrono::duration <double, milli> (diff).count() << " ms" << endl;
                    cout << "Numero de comparacoes: " << endl;
                    cout << numComparacoes << endl;
                    cout << "Numero de copias de registros: " << endl;
                    cout << numCopias << endl;
                    cout << "****************************"<< endl;
                }
                cout << endl << "-------------------" <<endl;
            }

        }
    }
}



int main()
{
    // HeapSort sort;

    // Registro *vet = teste(10);

    // for (int i = 0; i < 10; i++)
    //     cout << vet[i].getUserId() << " ";
    // cout << endl;
    // cout << endl;
    // cout << endl;

    // sort.heapSortObject(vet, 10);

    // for (int i = 0; i < 10; i++)
    //     cout << vet[i].getUserId() << " ";
    // cout << endl;

    LeArquivo();
    Menu();

    return 0;
}

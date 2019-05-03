#include <iostream>
#include <random>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <bits/stdc++.h>
#include "src/Headers/Registro.h";
#include "Startup.h";
#include "Construct.cpp";

using namespace std;

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
    case 2:
        startup.StartBubbleSort(vet, TAM);
    case 3:
        //startup.StartInsertionSort(vet, TAM);
    case 4:
        startup.StartMergeSort(vet, 0, TAM);
    case 5:
        startup.StartQuickSort(vet, 0, TAM);
    }

    cout << "Vetor depois de ordenar: " << endl;
    printVector(vet, TAM);

    delete[] vet;
}

void LeArquivo()
{
    Startup start;

    ifstream arquivo;
    arquivo.open("ratings.csv");

    if (arquivo.is_open())
    {
        arquivo.seekg(0, arquivo.end); // apontar para o final do arquivo
        
        ifstream entrada;
        entrada.open("entrada.txt");
        if (entrada.is_open())
        {
            while (!entrada.eof())
            {
                string tamanho;
                getline(entrada, tamanho);
                int TAM = atoi(tamanho.c_str()); // transformando tamanho para inteiro

                cout << "Gerando conjuntos de " << TAM << " Valores" << endl
                     << "-------------------" << endl;

                for (int i = 0; i < 5; i++) // rodar 5 vezes e gerar 5 conjuntos de elementos distintos de mesmo tamanho
                {
                    srand(time(NULL) * i + time(NULL));

                    cout << endl;
                    
                    Registro *registros = criaArrayRegistro(arquivo, TAM);
                    int *userIds = new int[TAM];

                    for(int i = 0; i < TAM; i++)
                        userIds[i] = registros[i].getUserId();

                    start.StartInsertionSort(registros, userIds, TAM);

                    

                    // cout << "Tempo: ";
                    // auto end = chrono::steady_clock::now();
                    // auto diff = end - start;
                    // cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;
                    // cout << endl
                    //      << endl;
                }

                cout << endl
                     << "-------------------" << endl;
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

    return 0;
}

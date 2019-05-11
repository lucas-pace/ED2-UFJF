#include <iostream>
#include <random>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <bits/stdc++.h>
#include <chrono>
#include "src/Headers/Registro.h";
#include "src/Headers/QuickSort.h";
#include "src/Headers/ShellSort.h";
#include "src/Headers/Saida.h";
#include "Startup.h";

using namespace std;
using namespace std::chrono;

/// Variaveis do quickSort.cpp que registram as estatisticas;
extern int numComparacoes;
extern int numCopias;

/**
 * Fun��o que troca o valor de duas vari�veis usando uma
 * vari�vel auxiliar
 *
 * @param int *x
 * @param int *y
 * @return void
*/
void swap(int *x, int *y)
{
    int aux = *x;
    *x = *y;
    *y = aux;
}

int* GeraVetorUserId(Registro registros[], int TAM)
{
    int *vetUserIds = new int();
    
    for(int i = 0; i < TAM; i++)
    {
        vetUserIds[i] = registros[i].getUserId();    
    }

    return vetUserIds;
}

void Distribuidor(Registro registros[], int userIds[], int algoritmo, ofstream &saida, int TAM)
{
    Startup startup;

    switch (algoritmo)
    {
    case 1:
        startup.StartInsertionSort(registros, userIds, TAM, saida);
        break;
    case 2:
        startup.StartHeapSort(registros, userIds, TAM, saida);
        break;
    case 3:
        startup.StartMergeSort(registros, userIds, 0, TAM, saida);
        break;
    case 4:
        startup.StartSelectionSort(registros, userIds, TAM, saida);
        break;
    case 5:
        startup.StartQuickSort(registros, userIds, 0, TAM - 1, saida);
        break;
    case 6:
        startup.StartBubbleSort(registros, userIds, TAM, saida);
        break;
    
    default:
        break;
    }
}

Registro *GetRegistrosPorConjunto(ifstream &arquivo, int TAM)
{
    Registro *registros = new Registro[TAM];

    int tamanhoArquivo = arquivo.tellg();

    for (int j = 0; j < TAM; j++)
    {
        srand(time(NULL) * j * time(NULL));

        registros[j] = registros->pegarKbAleatorio(arquivo, registros[j], tamanhoArquivo);
    }

    return registros;
}

void Run(int algoritmo, ofstream &saida)
{
    ifstream arquivo;
    ifstream entrada;

    arquivo.open("ratings.csv");
    entrada.open("entrada.txt");

    if (arquivo.is_open())
    {
        arquivo.seekg(0, arquivo.end); // apontar para o final do arquivo

        while (!entrada.eof())
        {
            string tamanho;
            getline(entrada, tamanho);

            int TAM = atoi(tamanho.c_str()); // transformando tamanho para inteiro

            for (int i = 0; i < 5; i++) // rodar 5 vezes e gerar 5 conjuntos de elementos distintos de mesmo tamanho
            {     
                Registro *registros = GetRegistrosPorConjunto(arquivo, TAM);
                int *userIds = GeraVetorUserId(registros, TAM);

                Distribuidor(registros, userIds, algoritmo, saida, TAM);
            }
        }
    }
}

void Menu()
{
    Saida saida;

    int option = 0;
    cout << "Escolha qual algoritmo voce quer usar: " << endl;
    cout << "[1] = Insertion Sort" << endl;
    cout << "[2] = Heap Sort" << endl;
    cout << "[3] = Merge Sort" << endl;
    cout << "[4] = Selection Sort" << endl;
    cout << "[5] = Quick Sort" << endl;
    cout << "[6] = Bubble Sort" << endl;

    cin >> option;

    switch (option)
    {
    case 1:
        saida.getInsertion();
        Run(1, saida.insertionSort);
        break;
    case 2:
        saida.getHeap();
        Run(2, saida.heapSort);
        break;
    case 3:
        saida.getMerge();
        Run(3, saida.mergeSort);
        break;
    case 4:
        saida.getSelection();
        Run(4, saida.selectionSort);
        break;
    case 5:
        saida.getQuick();
        Run(5, saida.quickSort);
        break;
    case 6:
        saida.getBubble();
        Run(6, saida.bubbleSort);
        break;
    }
}

int main()
{

    Menu();

    return 0;
}

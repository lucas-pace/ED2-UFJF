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

/**
 * Fun��o que imprime na tela os valores das chaves de um vetor
 *
 * @param int vet[]
 * @param int TAM
 * @return void
*/
void printVector(int vet[], int TAM)
{
    for (int i = 0; i < TAM; i++)
        cout << vet[i] << " ";
    cout << endl;
}

/**
 * Fun��o que preenche um vetor com n�meros aleat�rios
 *
 * @param int vet[]
 * @param int TAM
 * @return void
*/
void aleatoryVector(int vet[], int TAM)
{
    srand(time(NULL));
    for (int i = 0; i < TAM; i++)
    {
        vet[i] = rand() % 100;
    }
}

/**
 * Fun��o que gera valores para um vetor e o imprime
 *
 * @param int vet[]
 * @param int TAM
 * @return void
*/
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
    auto inicio = high_resolution_clock::now();
    // Executar alguma fun��o aqui
    auto fim = high_resolution_clock::now();
    auto duracao = duration_cast<microseconds>(fim - inicio);

    cout << "Tempo de execucao: "
         << duracao.count() << " microseconds" << endl;

    return 0;
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
    ShellSort *s = new ShellSort();

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
                    auto inicio = high_resolution_clock::now();
                    for(int j = 0; j < TAM; j++)
                    {
                        registros[j] = registros->pegarKbAleatorio(arquivo,registros[j], tamanhoArquivo);
                        cout << registros[j].getUserId() << " ";
                    }
                    cout << endl;
                    //q->quickSortMediana(registros, 0,TAM-1,5);
                    s->shellSort(registros, TAM);
                    cout << "Ordenado: " << endl;
                    for(int j = 0 ; j < TAM; j++)
                    {
                        cout << registros[j].getUserId() << " ";
                    }
                    cout << endl;
                    auto fim = high_resolution_clock::now();
                    auto duracao = duration_cast<microseconds>(fim - inicio);
                    cout << "Tempo de execucao: " << endl;
                    cout << duracao.count() << " microsegundos" << endl;
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

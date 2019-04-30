#include <iostream>
#include <random>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <bits/stdc++.h>
#include "src/Headers/Registro.h";
#include "Startup.h";

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

void insertionSort(Registro vet[], int TAM)
{
    for (int i = 1; i <= TAM; i++)
    {
        int valorAtual = vet[i].getUserId();
        for (int j = i - 1; j != 0 && vet[j - 1].getUserId() > vet[j].getUserId(); j--)
        {
            swap(vet[j], vet[j - 1]);
        }
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
        //insertionSort(vet, TAM);
    case 4:
        startup.StartMergeSort(vet, 0, TAM);
    case 5:
        startup.StartQuickSort(vet, 0, TAM);
    }

    cout << "Vetor depois de ordenar: " << endl;
    printVector(vet, TAM);

    delete[] vet;
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

void bubbleSort(Registro vet[], int TAM)
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

Registro *CriaArrayRegistro(ifstream& arquivo, int TAM)
{
    Registro registro;
    Registro *registros = new Registro[TAM];

    int tamanhoArquivo = arquivo.tellg();
    auto start = chrono::steady_clock::now();

    for (int j = 0; j < TAM; j++)
    {
        registros[j] = registro.pegarKbAleatorio(arquivo, registros[j], tamanhoArquivo);
        cout << registros[j].getMovieId() << " ";
    }

    return registros;
}

void LeArquivo()
{
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
                    cout << endl;
                    cout << endl;
                    cout << endl;

                    Registro *registros = CriaArrayRegistro(arquivo, TAM);

                    bubbleSort(registros, TAM);

                    cout << "Ordenado: " << endl;
                    cout << endl;
                    for (int j = 0; j < TAM; j++)
                    {
                        cout << registros[j].getMovieId() << " ";
                    }

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
    QuickSort sort;

    Registro *vet = teste(10);

    for (int i = 0; i < 10; i++)
        cout << vet[i].getUserId() << " ";
    cout << endl;
    cout << endl;
    cout << endl;

    bubbleSort(vet, 10);

    for (int i = 0; i < 10; i++)
        cout << vet[i].getUserId() << " ";
    cout << endl;

    //LeArquivo();

    return 0;
}

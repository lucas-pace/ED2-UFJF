#include <iostream>
#include <random>
using namespace std;

void *printVector(int vet[], int TAM)
{
    for(int i = 0; i < TAM; i++)
        cout << vet[i] << " ";
    cout << endl;
}

void *aleatoryVector(int vet[], int TAM)
{
    srand(time(NULL));
    for(int i = 0; i < TAM; i++)
    {
        vet[i] = rand() % 10;
    }
}

void *insertionSort(int vet[], int TAM)
{
    int valorAtual;
    for(int i = 1 ; i < TAM; i++)
    {
        for(int j = i; j != 0; j--)
        {
            if(vet[j-1] > vet[j])
            {
                valorAtual = vet[j];
                vet[j] = vet[j-1];
                vet[j-1] = valorAtual;
            }
        }
    }
}

void *bubbleSort(int vet[], int TAM )
{
    int aux;
    for(int i = 0; i < TAM; i++)
    {
        for(int j = 0 ; j < TAM-1; j++)
        {
            if(vet[j] > vet[j+1])
            {
                aux = vet[j];
                vet[j] = vet[j+1];
                vet[j+1] = aux;
            }
        }
    }
}


void *selectionSort(int vet[], int TAM)
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
        menor = vet[idMenor];
        vet[idMenor] = vet[i];
        vet[i] = menor;
    }
}

void generateAndPrint(int vet[], int TAM)
{
    aleatoryVector(vet, TAM);
    cout << "Vetor Atual:  ";
    printVector(vet, TAM);
}

int main()
{

    int TAM;
    cout << "Digite o tamanho do vetor: ";
    cin >> TAM;
    int vet[TAM];

    generateAndPrint(vet, TAM);

    int option = 0;
    cout << "Escolha qual algoritmo voce quer usar: " << endl;
    cout << "[1] = Selection Sort" << endl;
    cout << "[2] = Bubble Sort" << endl;
    cout << "[3] = Insertion Sort" << endl;
    cin >> option;
    switch(option){
        case 1: selectionSort(vet, TAM);
        case 2: bubbleSort(vet,TAM);
        case 3: insertionSort(vet, TAM);
        }

    printVector(vet, TAM);

    return 0;
}

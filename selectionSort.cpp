#include <iostream>
#include <stdlib.h>

using namespace std;

void print(int vet[], int tam)
{
  for(int i = 0; i < tam; i++)
  {
      cout << vet[i] << " ";
  }
  cout << endl;
}

void selectionSort(int vetor[], int tam)
{
    int menor = 0;
    print(vetor, tam);
    cout << "Ordenando: " << endl;
    for(int i = 0; i < tam - 2; i++)
    {
        menor = i;
        for(int j = i +1; j <= tam-1; j++)
        {
            if(vetor[j] < vetor[menor])
                menor = j;
        }
        int aux = 0;
        aux = vetor[i];
        vetor[i] = vetor[menor];
        vetor[menor] = aux;
    }
}

int main()
{
    cout << "Digite o tamanho do vetor" << endl;
    int tam = 0;
    cin >> tam;
    int vetor [tam];
    for(int i = 0; i < tam; i++)
    {
        vetor[i] = rand();
    }
    print(vetor,tam);
    selectionSort(vetor,tam);
    cout <<"Ordenando: " << endl;
    print(vetor,tam);

    return 0;
}

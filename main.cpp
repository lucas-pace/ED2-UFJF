#include <iostream>
#include <random>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <bits/stdc++.h>


using namespace std;


class Registro
{
    int userId, movieId;
    float rating;
private:
    Registro armazenaRegistro(ifstream, Registro);
public:
    Registro();
    ~Registro();

    int getUserId();
    void setUserId(int);

    int getMovieId();
    void setMovieId(int);

    float getRating();
    void setRating(float);
};

int Registro::getUserId()
{
    return this->userId;
}

void Registro::setUserId(int id)
{
    this->userId = id;
}

int Registro::getMovieId()
{
    return this->movieId;
}

void Registro::setMovieId(int id)
{
    this->movieId = id;
}

float Registro::getRating()
{
    return this->rating;
}

void Registro::setRating(float rating)
{
    this->rating = rating;
}

Registro::Registro()
{
}

Registro::~Registro() {}

Registro armazenaRegistro(ifstream& arquivo, Registro registro)
{

    string s;
    getline(arquivo,s,',');
    int userId = atoi(s.c_str());

    registro.setUserId(userId);

    getline(arquivo,s,',');
    int movieId = atoi(s.c_str());
    registro.setMovieId(movieId);


    getline(arquivo,s,',');
    float rating = atof(s.c_str());
    registro.setRating(rating);


    return registro;
}

Registro pegarKbAleatorio(ifstream& arquivo, Registro registro, int tam)
{

    string lixo;
    arquivo.seekg(rand() % tam, ios::beg); // procurar do inicio ate o fim do arquivo
    getline(arquivo,lixo); // joga a linha no lixo
    return armazenaRegistro(arquivo, registro);
}


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

                int TAM = atoi(tamanho.c_str());

                Registro *registros = new Registro[TAM];
                for(int i = 0; i < 5; i++)  // rodar 5 vezes e gerar 5 conjuntos de elementos distintos de mesmo tamanho
                {

                    for(int j = 0; j < TAM; j++)
                    {
                        registros[j] = pegarKbAleatorio(arquivo,registros[j], tamanhoArquivo);
                        cout << registros[j].getMovieId() << " ";

                    }
                    cout << endl;
                }

            cout << "---------------" << endl;
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

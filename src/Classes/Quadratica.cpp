#include "../Headers/Quadratica.h";
#include "../Headers/Hash.h"
#include <stdlib.h>
#include <iostream>
#include <string>

Quadratica::Quadratica(int tam)
{
    this->tam = tam;
    this->tabela = new long int[tam];
    this->colisoes = 0;
    this->qtdPosicoesPreenchidas = 0;
    this->inicializarTabela();
}


Quadratica::~Quadratica()
{
    delete []this->tabela;
}

long int Quadratica::getColisoes()
{
    return this->colisoes;
}

int Quadratica::funcaoHashing(int valor)
{

    return  valor%this->tam;
}

// Insercao de valores, alem do calculo de colisoes
void Quadratica::inserir(int valor)
{

    int posicaoInicial = funcaoHashing(valor);// Calcula a posicao com a funcao hashing.
    int posicao = posicaoInicial;
    int colisoesDentroLoop = 0;

    if(qtdPosicoesPreenchidas >= this->tam)
    {
        cout << "Tabela cheia" << endl;
    }
    else
    {
        /** Enquanto nao acha posicao vazia e enquanto não houver 50% de colisão para o tamanho do vetor, continuara em sondagem quadratica.
        Caso contrário, irá passar a percorrer em sondagem linear.
        */
        while(this->tabela[posicao] != -1 && colisoesDentroLoop < this->tam*0.5)
        {
            colisoes++;
            colisoesDentroLoop++;
            posicao = posicaoInicial+ colisoesDentroLoop*colisoesDentroLoop;
            posicao = funcaoHashing(posicao);
        }


        if(colisoesDentroLoop >= this->tam*0.5)
        {
            /** Irá percorrer linearmente a partir de agora. */
            posicao = funcaoHashing(posicao);

            while(this->tabela[posicao] != -1 )
            {
                colisoes++;
                posicao++;

                if(posicao >= tam)
                {
                    posicao = 0;
                }
            }
        }

        else
        {
            this->tabela[posicao] = valor; // caso encontrada posicao livre, inserir valor na tabela
            qtdPosicoesPreenchidas++;
        }
    }
}


void Quadratica::imprimirTabela()
{
    for(int i=0; i < this->tam; i++)
    {
        cout << this->tabela[i] << "   ";
    }
}



//Inicializar a tabela - preencher todas as posições com -1 (vazio).
void Quadratica::inicializarTabela()
{
    for(int i=0; i < this->tam; i++)
    {
        this->tabela[i] = -1;
    }
}

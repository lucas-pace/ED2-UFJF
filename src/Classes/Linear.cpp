#include "../Headers/Linear.h";
#include "../Headers/Hash.h"
#include <stdlib.h>
#include <iostream>
#include <string>

Linear::Linear(int tamanho)
{
    this->tam = tamanho;
    this->tabela = new long int[tam];
	this->colisoes = 0;
    this->qtdPosicoesPreenchidas = 0;
	this->inicializarTabela();
}


Linear::~Linear(){
    delete []this->tabela;
}

long int Linear::getColisoes(){
    return this->colisoes;
}

int Linear::funcaoHashing(int valor){

	return  valor%this->tam;
}

// Insercao de valores, alem do calculo de colisoes
void Linear::inserir(int valor){

    int posicao = funcaoHashing(valor);// Calcula a posicao pela funcao hashing.

    if(qtdPosicoesPreenchidas >= this->tam){
        cout << "Tabela cheia" << endl; // Imprime tabela cheia caso as posicoes vazias se esgotem
    }else{
		// Enquanto nao acha posicao vazia, acumula as colisoes e ira para a proxima posicao
        while(this->tabela[posicao] != -1){
            colisoes++;
            posicao++;

			// Caso chegue na ultima posicao, reinicia a contagem;
			if(posicao >= tam){
                posicao = 0;
            }
        }
        this->tabela[posicao] = valor; // caso encontrada posicao livre, inserir valor na tabela
        qtdPosicoesPreenchidas++;
    }
}


void Linear::imprimirTabela(){
    for(int i=0; i < this->tam; i++){
        cout << this->tabela[i] << "   ";
    }
}



//Inicializar a tabela - preencher todas as posições com -1 (vazio).
void Linear::inicializarTabela(){
    for(int i=0; i < this->tam; i++){
        this->tabela[i] = -1;
    }
}

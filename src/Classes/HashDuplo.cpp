#include "../Headers/HashDuplo.h"
#include <iostream>

using namespace std;

/**
 * Construtor da Classe, cria um vetor do tamanho definido no .h
 * e preenche todas as posi��es com -1
 *
 * @param  int chave
 * @return void
*/
HashDuplo::HashDuplo()
{
    tabelaHash = new int[TAMANHO_TABELA];
    tamanhoAtual = 0;
    for (int i=0; i<TAMANHO_TABELA; i++)
        tabelaHash[i] = -1;
}

/**
 * Verifica se a tabela est� cheia.
 *
 * @return bool
*/
bool HashDuplo::estaCheio()
{
    if(tamanhoAtual = TAMANHO_TABELA)
        return true;
    else
        return false;
}

/**
 * Insere uma chave na tabela e trata colis�o caso ocorra.
 *
 * @param  int chave
 * @return void
*/
void HashDuplo::insereChave(int chave)
{
    if (estaCheio())
        return;

    /// pega o indice da primeira fun��o de hash
    int indice = funcaoHashPrimaria(chave);

    /// caso ocorra uma colis�o
    if (tabelaHash[indice] != -1)
    {
        int indice2 = funcaoHashSecundaria(chave);
        int i = 1;
        while (1)
        {
            int novoIndice = (indice + i * indice2) % TAMANHO_TABELA;

            if (tabelaHash[novoIndice] == -1)
            {
                tabelaHash[novoIndice] = chave;
                break;
            }
                i++;
        }
    }
        else
            tabelaHash[indice] = chave;
        tamanhoAtual++;
}

/**
 * Deleta uma chave se ela for encontrada na tabela
 *
 * @param  int chave
 * @return void
*/
void HashDuplo::deletaChave(int chave)
{
    for(int i = 0; i < TAMANHO_TABELA; i++)
    {
        if(i == chave)
        {
            tabelaHash[i] == -1;
            break;
        }
    }
}

/**
 * Fun��o de Hash padr�o
 *
 * @param  int chave
 * @return int
*/
int HashDuplo::funcaoHashPrimaria(int chave)
{
    return (chave % TAMANHO_TABELA);
}

/**
 * Fun��o de Hash secund�ria caso haja a colis�o
 *
 * @param  int chave
 * @return int
*/
int HashDuplo::funcaoHashSecundaria(int chave)
{
    return (PRIMO - (chave % PRIMO));
}

/**
 * Fun��o que imprime uma representa��o da tabela de Hash
 *
 * @param  int chave
 * @return int
*/
void HashDuplo::imprimeHash()
{
    for (int i = 0; i < TAMANHO_TABELA; i++)
    {
        if (tabelaHash[i] != -1)
            cout << i << " --> " << tabelaHash[i] << endl;
        else
            cout << i << endl;
    }
}

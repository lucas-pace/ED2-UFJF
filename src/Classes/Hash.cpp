#include "../Headers/Hash.h"

using namespace std;

Hash::Hash(int tam)
{
    this->balde = tam;
    tabela = new list<int>[balde];
}

/**
 * Insere a chave na tabela de hash
 *
 * @param  int chave
 * @return void
*/
void Hash::insereItem(int chave)
{
    int indice = funcaoHash(chave);
    tabela[indice].push_back(chave);
}

/**
 * Função de hash que retorna o resto de x dividido pelo tamanho do balde
 *
 * @param  int x
 * @return int
*/
int Hash::funcaoHash(int x)
{
    return (x % balde);
}

/**
 * Deleta uma chave se ela for encontrada na tabela
 *
 * @param  int chave
 * @return void
*/
void Hash::deletaItem(int chave)
{
  int indice = funcaoHash(chave);

  /// procura pela a chave na tabela
  list <int> :: iterator i;
  for (i = tabela[indice].begin(); i != tabela[indice].end(); i++) {
    if (*i == chave)
      break;
  }

  /// Se a chave for encontrada, ela é deletada
  if (i != tabela[indice].end())
    tabela[indice].erase(i);
}

/**
 * Imprime o Hash
 *
 * @return void
*/
void Hash::imprimeHash() {
  for (int i = 0; i < balde; i++) {
    cout << i;
    for (auto x : tabela[i])
      cout << " --> " << x;
    cout << endl;
  }
}

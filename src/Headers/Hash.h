#ifndef HASH_H_INCLUDED
#define HASH_H_INCLUDED
#include<iostream>
#include <list>

using namespace std;

class Hash
{
    int balde;
    list<int> *tabela;

    public:
        Hash();

        Hash(int tam);

        void insereItem(int x);

        void deletaItem(int chave);

        int funcaoHash(int x);

        void imprimeHash();
};

#endif // HASH_H_INCLUDED

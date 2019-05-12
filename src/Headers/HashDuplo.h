#ifndef HASHDUPLO_H_INCLUDED
#define HASHDUPLO_H_INCLUDED

#define TAMANHO_TABELA 13

/// Usada na segunda função de Hash
#define PRIMO 7

class HashDuplo
{

    public:

        HashDuplo();
        int funcaoHashPrimaria(int chave);
        int funcaoHashSecundaria(int chave);
        void insereChave(int chave);
        void deletaChave(int chave);
        bool estaCheio();
        void imprimeHash();

    private:

        int *tabelaHash;
        int tamanhoAtual;
};
#endif // HASHDUPLO_H_INCLUDED

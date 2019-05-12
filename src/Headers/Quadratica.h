#ifndef QUADRATICA_H_INCLUDED
#define QUADRATICA_H_INCLUDED


class Quadratica {
public:
	Quadratica(int tamanho);
	~Quadratica();
	long int getColisoes();
    void inserir(int valor);
    void imprimirTabela();
private:
	int tam;
	long int* tabela;
	long colisoes;
	int qtdPosicoesPreenchidas;
	void inicializarTabela();
	int funcaoHashing(int valor);

};


#endif // QUADRATICA_H_INCLUDED

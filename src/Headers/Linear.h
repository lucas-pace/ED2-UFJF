#ifndef LINEAR_H_INCLUDED
#define LINEAR_H_INCLUDED


class Linear{
public:
	Linear(int tamanho);
	~Linear();
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


#endif // LINEAR_H_INCLUDED

#include "src/Headers/Registro.h";

Registro pegarKbAleatorio(ifstream &arquivo, Registro registro, int tam)
{
    string lixo;
    arquivo.seekg(rand() % tam, ios::beg); // procurar do inicio ate o fim do arquivo
    getline(arquivo, lixo);                // joga a linha no lixo

    return Registro::criaRegistro(arquivo, registro);
}

Registro *criaArrayRegistro(ifstream &arquivo, int TAM)
{
    Registro *registros = new Registro[TAM];

    int tamanhoArquivo = arquivo.tellg();

    cout << endl;
    cout << endl;

    cout << "Array original"
         << ": ";
    for (int j = 0; j < TAM; j++)
    {
        registros[j] = pegarKbAleatorio(arquivo, registros[j], tamanhoArquivo);
        cout << registros[j].getUserId() << " ";
    }

    cout << endl;
    cout << endl;

    return registros;
}

int tempoProcessamento()
{
    auto start = chrono::steady_clock::now();
    cout << "Tempo: ";
    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;
    cout << endl
         << endl;
}

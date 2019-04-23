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

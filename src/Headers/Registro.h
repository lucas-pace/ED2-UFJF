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

    Registro pegarKbAleatorio(ifstream &arquivo, Registro registro, int tam);
};

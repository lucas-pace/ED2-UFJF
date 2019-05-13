#ifndef SHELLSORT_H_INCLUDED
#define SHELLSORT_H_INCLUDED

#include <iostream>
#include <stdlib.h>
#include <chrono>

#include "../Headers/Registro.h";

using namespace std;

class ShellSort
{
    public:
        int numComparacoes = 0;
        int numCopias = 0;
        void shellSort(Registro arr[], int tam);
};


#endif // SHELLSORT_H_INCLUDED

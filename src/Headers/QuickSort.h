#ifndef _QUICKSORT_H_
#define _QUICKSORT_H_

#include <iostream>
#include <stdlib.h>

using namespace std;

class QuickSort
{
    public:
        void quickSort(int arr[], int low, int high);
    
    private:
        int partition(int arr[], int low, int high);
};

#endif
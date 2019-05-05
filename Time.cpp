#include <iostream>
#include <math.h>
#include <chrono>
#include "src/Headers/Time.h"

using namespace std;

template<class T>

void Time<T>::printTime(T&& diff)
{
   cout << "Tempo : " << chrono::duration<double, milli>(diff).count() << " ms" << endl;
   cout << endl;
}

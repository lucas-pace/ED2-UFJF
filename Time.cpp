#include <iostream>
#include <math.h>

template<class T>
void printime(T&& diff)
{
   cout << "Tempo : " << chrono::duration<double, milli>(diff).count() << " ms" << endl;
   cout << endl;
}
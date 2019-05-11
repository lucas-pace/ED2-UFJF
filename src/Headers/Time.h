#ifndef TIME_H_INCLUDED
#define TIME_H_INCLUDED

#include <iostream>
#include <math.h>
#include <chrono>

using namespace std;
using namespace std::chrono;

class Time {

public:

    Time();
    ~Time();

    double static tempoProcessamento(high_resolution_clock::time_point t1, high_resolution_clock::time_point t2);
};


#endif // TIME_H_INCLUDED

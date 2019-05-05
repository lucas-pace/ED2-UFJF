#ifndef TIME_H_INCLUDED
#define TIME_H_INCLUDED

#include <chrono>
#include <math.h>

using namespace std;


template<class T> class Time {

public:

    Time();
    ~Time();

    void printTime(T&& diff);



};


#endif // TIME_H_INCLUDED

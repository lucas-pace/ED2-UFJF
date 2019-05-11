#include "../Headers/Time.h";

double Time::tempoProcessamento(high_resolution_clock::time_point t1, high_resolution_clock::time_point t2)
{
    duration<double> time_spanQ = duration_cast<duration<double,nano>>(t2 - t1);
    
    return time_spanQ.count();
}
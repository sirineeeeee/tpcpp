#ifndef TIMESERIESGENERATOR_H
#define TIMESERIESGENERATOR_H

#include <vector>
#include <iostream>
using namespace std;

class TimeSeriesGenerator {
public:
    TimeSeriesGenerator();
    TimeSeriesGenerator(int _seed);

    virtual vector<double> generateTimeSeries(int _size) = 0;

    static void printTimeSeries(const vector<double>& vect);

    int seed;
};

#endif // TIMESERIESGENERATOR_H
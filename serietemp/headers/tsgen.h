#ifndef TSGEN_H
#define TSGEN_H

#include <cmath>
#include <random>
using namespace std; 


class TimeSeriesGenerator {
    public:
        TimeSeriesGenerator();
        TimeSeriesGenerator(int);

        virtual vector<double> generateTimeSeries(int);
        void printTimeSeries(const vector<double>);
        int seed;
        
};

#endif
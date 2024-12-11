#include "headers/tsgen.h"

TimeSeriesGenerator::TimeSeriesGenerator() : seed(0) {}

TimeSeriesGenerator::TimeSeriesGenerator(int _seed) : seed(_seed) {}

void TimeSeriesGenerator::printTimeSeries(const vector<double>& vect) {
    for (double d : vect) {
        cout << d << " ";
    }
    cout << endl;
}
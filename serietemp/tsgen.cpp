#include "headers/tsgen.h"
#include <iostream> 
using namespace std;
TimeSeriesGenerator::TimeSeriesGenerator():
seed(0)
{}

TimeSeriesGenerator::TimeSeriesGenerator(int _seed):
seed(_seed)
{}

vector<double> TimeSeriesGenerator::generateTimeSeries(int _size){
    srand(seed);
    vector<double> ret;
    ret.reserve(_size);
    for (int i =0; i< _size; i++)
        ret.push_back(rand());
    return ret;
}

void TimeSeriesGenerator::printTimeSeries(const vector<double> vect){
    for(double d : vect) 
        cout << d;
}
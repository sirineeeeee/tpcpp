#include "headers/sin.h"

SinWaveGenerator::SinWaveGenerator():
TimeSeriesGenerator(0)
{}

SinWaveGenerator::SinWaveGenerator(int _seed):
TimeSeriesGenerator(_seed)
{}

//A IMPLEMENTER
vector<double> SinWaveGenerator::generateTimeSeries(int _size){
    srand(seed);
    vector<double> ret;
    ret.reserve(_size);
    for (int i =0; i< _size; i++)
        ret.push_back(rand());
    return ret;
}

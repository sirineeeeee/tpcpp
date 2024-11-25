#include "headers/stp.h"

StepGenerator::StepGenerator():
TimeSeriesGenerator()
{}


StepGenerator::StepGenerator(int _seed):
TimeSeriesGenerator(_seed)
{}


vector<double> StepGenerator::generateTimeSeries(int _size){
    vector<double> ret;
    ret.reserve(_size);
    srand(seed);
    double n;
    for (int i =0; i< _size; i++){
        if (rand()/1){
            srand(seed);
            n = rand();
        }
        ret.push_back(n);
    }
    return ret;
}
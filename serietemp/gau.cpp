#include "headers/gau.h"

GaussianGenerator::GaussianGenerator():
TimeSeriesGenerator(),
mean(0.0),
std_dev(0.0)
{}

GaussianGenerator::GaussianGenerator(int _seed):
TimeSeriesGenerator(_seed),
mean(0.0),
std_dev(0.0)
{}

vector<double> GaussianGenerator::generateTimeSeries(int _size){
    vector<double> ret;
    ret.reserve(_size);
    for (int i =0; i< _size; i++){
        double u1 = (double) rand(); 
        double u2 = (double) rand(); 
        double z0 = sqrt(-2.0 * log(u1)) * cos(2 * M_PI * u2);
        ret.push_back(z0 * std_dev + mean);
    }
    return ret;
}


#ifndef GAUSSIANGENERATOR_H
#define GAUSSIANGENERATOR_H

#include "tsgen.h"
#include <random>

class GaussianGenerator : public TimeSeriesGenerator {
public:
    GaussianGenerator();
    GaussianGenerator(double mean, double stddev, int _seed);
    

    vector<double> generateTimeSeries(int _size) override;

private:
    double mean;
    double stddev;
};

#endif // GAUSSIANGENERATOR_H
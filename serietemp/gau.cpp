#include "headers/gau.h"

GaussianGenerator::GaussianGenerator()
    : GaussianGenerator(0.0, 1.0, 0) {}


GaussianGenerator::GaussianGenerator(double mean, double stddev, int _seed)
    : TimeSeriesGenerator(_seed), mean(mean), stddev(stddev) {}


vector<double> GaussianGenerator::generateTimeSeries(int _size) {
    default_random_engine generator(seed);
    normal_distribution<double> distribution(mean, stddev);

    vector<double> series;
    series.reserve(_size);
    for (int i = 0; i < _size; ++i) {
        series.push_back(distribution(generator));
    }
    return series;
}

#include "headers/stp.h"

StepGenerator::StepGenerator(int _seed) : TimeSeriesGenerator(_seed) {}

StepGenerator::StepGenerator() : StepGenerator(0) {}

vector<double> StepGenerator::generateTimeSeries(int _size) {
    srand(seed);
    vector<double> series;
    series.reserve(_size);

    double previous = 0;
    series.push_back(previous);
    for (int i = 1; i < _size; ++i) {
        if (rand() % 2 == 0) {
            previous = rand() % 101;
        }
        series.push_back(previous);
    }
    return series;
}

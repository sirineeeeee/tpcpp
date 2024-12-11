#include "headers/sin.h"

SinWaveGenerator::SinWaveGenerator(double amplitude, double frequency, double phase, int _seed)
    : TimeSeriesGenerator(_seed), amplitude(amplitude), frequency(frequency), phase(phase) {}

SinWaveGenerator::SinWaveGenerator() : SinWaveGenerator(1.0, 1.0, 0.0, 0) {}

vector<double> SinWaveGenerator::generateTimeSeries(int _size) {
    vector<double> series;
    series.reserve(_size);
    for (int i = 0; i < _size; ++i) {
        series.push_back(amplitude * sin(frequency * i + phase));
    }
    return series;
}
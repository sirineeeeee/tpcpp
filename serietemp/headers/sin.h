#ifndef SINWAVEGENERATOR_H
#define SINWAVEGENERATOR_H

#include "tsgen.h"
#include <cmath>

class SinWaveGenerator : public TimeSeriesGenerator {
public:
    SinWaveGenerator(double amplitude, double frequency, double phase, int _seed = 0);
    SinWaveGenerator();

    vector<double> generateTimeSeries(int _size) override;

private:
    double amplitude;
    double frequency;
    double phase;
};

#endif // SINWAVEGENERATOR_H
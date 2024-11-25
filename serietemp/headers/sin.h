#ifndef SIN_H
#define SIN_H
#include "tsgen.h"

class SinWaveGenerator : TimeSeriesGenerator{
    public:
        SinWaveGenerator();
        SinWaveGenerator(int);

        vector<double> generateTimeSeries(int) override;
};

#endif
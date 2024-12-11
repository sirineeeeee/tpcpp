#ifndef STEPGENERATOR_H
#define STEPGENERATOR_H

#include "tsgen.h"
#include <cstdlib>

class StepGenerator : public TimeSeriesGenerator {
public:
    StepGenerator(int _seed);
    StepGenerator();

    vector<double> generateTimeSeries(int _size) override;
};

#endif // STEPGENERATOR_H
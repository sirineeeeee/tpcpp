#ifndef STP_H
#define STP_H
#include "tsgen.h"

class StepGenerator : public TimeSeriesGenerator{
    public:
        StepGenerator();
        StepGenerator(int);
        vector<double> generateTimeSeries(int) override;

};

#endif
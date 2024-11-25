#ifndef GAU_H
#define GAU_H
#include "tsgen.h"

class GaussianGenerator : public TimeSeriesGenerator{
    public:
        GaussianGenerator();
        GaussianGenerator(int);

        vector<double> generateTimeSeries(int) override;
    private:
        double mean;
        double std_dev;

};

#endif
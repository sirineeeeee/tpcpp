#ifndef TSDATA_H
#define TSDATA_H

#include <cmath>
#include <random>
using namespace std; 
#include "tsgen.h"


class TimeSeriesDataset {
    public:
        TimeSeriesDataset();
        TimeSeriesDataset(bool,bool);

        void addTimeSeries(vector<double>,bool);
        void addTimeSeries(vector<double>);

    private:
        bool znormalize;
        bool isTrain;
        vector<double> data;
        vector<int> labels;
        int maxLength;  
        int numberOfSamples;  
};

#endif
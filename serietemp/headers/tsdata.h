#ifndef TIMESERIESDATASET_H
#define TIMESERIESDATASET_H

#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>
using namespace std;

class TimeSeriesDataset {
public:
    TimeSeriesDataset(bool znormalize = false, bool isTrain = true);

    void addTimeSeries(const vector<double>& series, int label = -1);

private:
    vector<double> zNormalize(const vector<double>& series);

public:
    bool znormalize;
    bool isTrain;
    vector<vector<double>> data;
    vector<int> labels;
    int maxLength;
    int numberOfSamples;
};

#endif // TIMESERIESDATASET_H
#ifndef KNN_H
#define KNN_H

#include "tsdata.h"
#include <string>
#include <map>
#include <algorithm>
using namespace std;

class KNN {
public:
    KNN(int k, const string& similarityMeasure);

    double evaluate(const TimeSeriesDataset& trainData, const TimeSeriesDataset& testData, const vector<int>& groundTruth);

private:
    int k;
    string similarityMeasure;

    double similarityMeasureFunc(const vector<double>& series1, const vector<double>& series2);
    double euclideanDistance(const vector<double>& series1, const vector<double>& series2);
    double dynamicTimeWarping(const vector<double>& series1, const vector<double>& series2);
};

#endif // KNN_H
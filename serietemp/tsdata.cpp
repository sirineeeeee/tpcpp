#include "headers/tsdata.h"

TimeSeriesDataset::TimeSeriesDataset(bool znormalize, bool isTrain)
    : znormalize(znormalize), isTrain(isTrain), maxLength(0), numberOfSamples(0) {}

void TimeSeriesDataset::addTimeSeries(const vector<double>& series, int label) {
    vector<double> normalizedSeries = series;
    if (znormalize) {
        normalizedSeries = zNormalize(series);
    }

    data.push_back(normalizedSeries);
    if (label != -1) {
        labels.push_back(label);
    }
    maxLength = max(maxLength, (int)series.size());
    ++numberOfSamples;
}

vector<double> TimeSeriesDataset::zNormalize(const vector<double>& series) {
    double mean = accumulate(series.begin(), series.end(), 0.0) / series.size();
    double variance = accumulate(series.begin(), series.end(), 0.0,
        [mean](double acc, double val) { return acc + (val - mean) * (val - mean); });
    double stddev = sqrt(variance / series.size());

    vector<double> normalized(series.size());
    transform(series.begin(), series.end(), normalized.begin(),
        [mean, stddev](double val) { return (val - mean) / stddev; });

    return normalized;
}

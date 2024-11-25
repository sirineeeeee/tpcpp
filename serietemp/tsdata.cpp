#include "headers/tsdata.h"

TimeSeriesDataset::TimeSeriesDataset():
znormalize(false),
isTrain(false)
{}

TimeSeriesDataset::TimeSeriesDataset(bool _znormalize,bool _isTrain):
znormalize(_znormalize),
isTrain(_isTrain)
{}

void TimeSeriesDataset::addTimeSeries(vector<double> vect,bool b){

}

void TimeSeriesDataset::addTimeSeries(vector<double> vect){

}
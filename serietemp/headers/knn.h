#ifndef KNN_H
#define KNN_H
#include "tsdata.h"

class KNN {
    public:
        KNN(int,string);
        int evaluate(TimeSeriesDataset,TimeSeriesDataset,vector<int>);

    private:
        int k;
        string similarity_measure;

};

#endif
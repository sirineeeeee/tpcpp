// KNN.cpp
#include "headers/knn.h"

KNN::KNN(int k, const string& similarityMeasure) : k(k), similarityMeasure(similarityMeasure) {}

double KNN::similarityMeasureFunc(const vector<double>& series1, const vector<double>& series2) {
    if (similarityMeasure == "euclidean_distance") {
        return euclideanDistance(series1, series2);
    } else if (similarityMeasure == "dtw") {
        return dynamicTimeWarping(series1, series2);
    }
    throw invalid_argument("Unsupported similarity measure");
}

double KNN::evaluate(const TimeSeriesDataset& trainData, const TimeSeriesDataset& testData, const vector<int>& groundTruth) {
    vector<int> predictions;
    for (const auto& testSeries : testData.data) {
        vector<pair<double, int>> distances;
        for (size_t i = 0; i < trainData.data.size(); ++i) {
            double dist = similarityMeasureFunc(testSeries, trainData.data[i]);
            distances.emplace_back(dist, trainData.labels[i]);
        }
        sort(distances.begin(), distances.end());

        map<int, int> classCounts;
                // Continue the evaluate function
        for (int i = 0; i < k; ++i) {
            classCounts[distances[i].second]++;  // Increment the count for the predicted class
        }

        // Find the class with the maximum count
        int predictedClass = -1;
        int maxCount = 0;
        for (const auto& count : classCounts) {
            if (count.second > maxCount) {
                maxCount = count.second;
                predictedClass = count.first;
            }
        }

        predictions.push_back(predictedClass);
    }

    // Calculate accuracy
    int correct = 0;
    for (size_t i = 0; i < groundTruth.size(); ++i) {
        if (predictions[i] == groundTruth[i]) {
            correct++;
        }
    }

    return static_cast<double>(correct) / groundTruth.size();  // Return the accuracy
}

// Euclidean Distance function
double KNN::euclideanDistance(const vector<double>& series1, const vector<double>& series2) {
    if (series1.size() != series2.size()) {
        throw invalid_argument("Time series must have the same length");
    }

    double sum = 0.0;
    for (size_t i = 0; i < series1.size(); ++i) {
        sum += (series1[i] - series2[i]) * (series1[i] - series2[i]);
    }
    return sqrt(sum);
}

// Dynamic Time Warping (DTW) function (simplified version)
double KNN::dynamicTimeWarping(const vector<double>& series1, const vector<double>& series2) {
    size_t n = series1.size();
    size_t m = series2.size();
    vector<vector<double>> dtw(n + 1, vector<double>(m + 1, numeric_limits<double>::infinity()));

    dtw[0][0] = 0.0;
    for (size_t i = 1; i <= n; ++i) {
        for (size_t j = 1; j <= m; ++j) {
            double cost = abs(series1[i - 1] - series2[j - 1]);
            dtw[i][j] = cost + min({dtw[i - 1][j], dtw[i][j - 1], dtw[i - 1][j - 1]});
        }
    }
    return dtw[n][m];
}

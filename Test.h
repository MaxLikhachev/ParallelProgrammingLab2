#pragma once
#include <iostream>
#include <vector>
#include <omp.h>
#include <cmath>

#include "Calculator.h" 
#include "TestTypes.h"
#include "Analyser.h"

double globalDeviage = 0.0;

template <typename T>
double test(vector<vector<T>> matrix, TestTypes type) {
    int size = matrix.size();
    vector<T> result(size, 0.0);
    double start = omp_get_wtime();
    switch (type)
    {
    case TestTypes::SEQUENTIAL: result = sequentialCalculate(matrix); break;
    case TestTypes::PARALLEL_CYCLES: result = parallelCyclesCalculate(matrix); break;
    case TestTypes::PARALLEL_SECTIONS: result = parallelSectionsCalculate(matrix); break;
    case TestTypes::PARALLEL_ALGORITHM: result = parallelAlgorithmCalculate(matrix); break;
    default: break;
    }
    double end = omp_get_wtime(), time = (end - start) * 1000;
    globalDeviage = averageDeviationCalculate(matrix, result);
    return time;
}

template <typename T>
void tests(vector<vector<T>> matrix, vector<TestTypes> types, int count)
{
    vector<vector<double>> times(types.size(), vector<double>(count, 0.0));
    for (int i = 0; i < types.size(); i++)
    {
        getTestType(types[i]);
        cout << " test... ";
        for (int j = 0; j < count; j++)
            times[i][j] = test(matrix, types[i]);
        cout << "successfully with " << globalCount << " iterations and deviage: " << globalDeviage << endl;
    }
    analyse(times, types);
}


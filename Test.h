#pragma once
#include <iostream>
#include <vector>
#include <omp.h>

#include "Random.h"
#include "Calculator.h" 
#include "TestTypes.h"
#include "Analyser.h"

template <typename T>
double test(vector<vector<T>> array, TestTypes type) {
    int size = array.size();
    vector<T>result(size, 0.0);
    double start = omp_get_wtime();

    switch (type)
    {
    case TestTypes::SEQUENTIAL: result = sequentialCalculate(array); break;
    default: break;
    }

    double end = omp_get_wtime(), time = (end - start) * 1000;

    if (averageDeviationCalculate(array, result) != 0.0)
        cout << "ERROR: solution not correct";

    cout << "Solution: ";
    for (int i = 0; i < result.size(); i++)
        cout << result[i] << " ";
    cout << endl;

    return time;
}

template <typename T>
void tests(vector<vector<T>> array, vector<TestTypes> types, int count)
{
    vector<vector<double>> times(types.size(), vector<double>(count, 0.0));

    for (int i = 0; i < types.size(); i++)
    {
        cout << getTestType(types[i]) << " testing...\n";
        for (int j = 0; j < count; j++)
            times[i][j] = test(array, types[i]);

        cout << getTestType(types[i]) << " tested\n\n";
    }

    analyse(times, types);
}


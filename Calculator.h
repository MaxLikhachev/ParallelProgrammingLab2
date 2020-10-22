#pragma once
#include <iostream>
#include <vector>
#include <cmath>
#include <omp.h>

using namespace std;

const double accuracy = 0.05;
const double eps = 0.0000000000001;

template <typename T>
bool IsDiagonalDominanceBroken(vector<vector<T>> a)
{
    bool flag = true;
    int size = a.size();
    for (int i = 0; i < size && flag; i++)
    {
        T fabsSum = 0.0;
        for (int j = 0; j < size; j++)
            if (i != j)
                fabsSum += fabs(a[i][j]);
        flag = fabs(a[i][i]) <= fabsSum;
    }
    return flag;
}

template <typename T>
bool IsDiverged(vector<T> x, vector<T> xn, T eps)
{
    bool flag = true;
    int size = x.size();
    for (int i = 0; i < size && flag; i++)
        flag = fabs(xn[i] - x[i]) < eps;
    return flag;
}

// ѕоследовательный метод
template <typename T>
vector<T> sequentialCalculate(vector<vector<T>> a)
{
	int size = a.size();
    vector<T> x(size, 0.0);
    vector<T> xn(size, 0.0);

    int count = 0;
    for (bool flag = !IsDiagonalDominanceBroken(a); flag; count++)
    //for (bool flag = true; flag; count++)
    {
        for (int i = 0; i < size; i++)
        {
            T sum = 0.0;
            for (int j = 0; j < size; j++)
                if (i != j)
                    sum += a[i][j] * x[j];
            xn[i] = (a[i][size] - sum) / a[i][i];
        }
        flag = !IsDiverged(x, xn, eps);
        if (flag)
            for (int i = 0; i < size; i++)
                x[i] = xn[i];
    }

    cout << "Iterations count = " << count << endl;
    for (int i = 0; i < size; i++)
        cout << " x[" << i << "] = " << x[i];
    cout << endl;
    return x;
}
// ѕроверка отклонений значений от последовательного вычислени€
template <typename T>
T averageDeviationCalculate(vector<vector<T>> array, vector<T> result)
{
    int size = array.size();
    bool flag = true;
    for (int i = 0; i < size; i++)
    {
        T sum = 0.0;
        for (int j = 0; j < size; j++)
            sum += array[i][j] * result[j];
        flag = sum == array[i][size];
        cout << "Checking [" << i << "] : calculated: " << sum << " expected: " << array[i][size] << endl;
    }
    return flag;
}
#pragma once
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

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

template <typename T>
void Iter(T typeExample)
{
    int size = 4;
    vector<vector<T>> a(size, vector<T>(size + 1, 0.0));
    vector<T> x(size, 0.0);
    vector<T> xn(size, 0.0);

    a[0][0] = -19.0, a[0][1] = 2.0, a[0][2] = -1.0, a[0][3] = -8.0, a[0][4] = 38.0;
    a[1][0] = 2.0, a[1][1] = 14.0, a[1][2] = 0.0, a[1][3] = -4.0, a[1][4] = 20.0;
    a[2][0] = 6.0, a[2][1] = -5.0, a[2][2] = -20.0, a[2][3] = -6.0, a[2][4] = 52.0;
    a[3][0] = -6.0, a[3][1] = 4.0, a[3][2] = -2.0, a[3][3] = 15.0, a[3][4] = 43.0;

    T eps = 0.0000000000001;
    int count = 0;
    for (bool flag = !IsDiagonalDominanceBroken(a); flag; count++)
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
}
#pragma once
#include <iostream>
#include <vector>
#include <cmath>
#include <omp.h>

using namespace std;

const double eps = 0.0000000000001;
int globalCount = 0;

template <typename T>
bool isDiagonalDominanceBroken(vector<vector<T>> matrix)
{
    bool flag = true;
    int size = matrix.size();
    for (int i = 0; i < size && flag; i++)
    {
        T fabsSum = 0.0;
        for (int j = 0; j < size; j++)
            if (i != j)
                fabsSum += fabs(matrix[i][j]);
        flag = fabs(matrix[i][i]) <= fabsSum;
    }
    return flag;
}

template <typename T>
bool isDiverged(vector<T> result, vector<T> temp, T eps)
{
    bool flag = true;
    int size = result.size();
    for (int i = 0; i < size && flag; i++)
        flag = fabs(temp[i] - result[i]) < eps;
    return flag;
}

// M���� ����������������� � �������������� ���������
template <typename T>
vector<T> parallelAlgorithmCalculate(vector<vector<T>> matrix)
{
    int size = matrix.size();
    vector<T> result(size, 0.0);
    vector<T> temp(size, 0.0);
    int count = 0;
    for (bool flag = !isDiagonalDominanceBroken(matrix); flag; count++)
    {
#pragma omp parallel for
        for (int i = 0; i < size; i++)
        {
            T sum = 0.0;
            {
#pragma omp parallel for
                for (int j = 0; j < size; j++)
                    if (i != j)
                        sum += matrix[i][j] * result[j];
                temp[i] = (matrix[i][size] - sum) / matrix[i][i];
            }
        }
        flag = !isDiverged(result, temp, eps);
        if (flag)
            for (int i = 0; i < size; i++)
            result[i] = temp[i];
    }
    globalCount = count;
    return result;
}

// M���� ����������������� � �������������� ������������ ������
template <typename T>
vector<T> parallelSectionsCalculate(vector<vector<T>> matrix)
{

    int size = matrix.size();
    vector<T> result(size, 0.0);
    vector<T> temp(size, 0.0);
    int count = 0;

    for (bool flag = !isDiagonalDominanceBroken(matrix); flag; count++)
    {
#pragma omp parallel sections
        {
#pragma omp section
            {
                for (int i = 0; i < size * 0.25; i++)
                {
                    T sum = 0.0;

                    for (int j = 0; j < size; j++)
                        if (i != j)
                            sum += matrix[i][j] * result[j];
                        temp[i] = (matrix[i][size] - sum) / matrix[i][i];
                }
            }
#pragma omp section
            {
                for (int i = size * 0.25; i < size * 0.5; i++)
                {
                    T sum = 0.0;

                    for (int j = 0; j < size; j++)
                         if (i != j)
                            sum += matrix[i][j] * result[j];
                        temp[i] = (matrix[i][size] - sum) / matrix[i][i];
                }
            }
#pragma omp section
            {
                for (int i = size * 0.5; i < size * 0.75; i++)
                {
                    T sum = 0.0;

                    for (int j = 0; j < size; j++)
                        if (i != j)
                            sum += matrix[i][j] * result[j];
                        temp[i] = (matrix[i][size] - sum) / matrix[i][i];
                }
            }
#pragma omp section
            {
                for (int i = size * 0.75; i < size; i++)
                {
                    T sum = 0.0;

                    for (int j = 0; j < size; j++)
                        if (i != j)
                            sum += matrix[i][j] * result[j];
                    temp[i] = (matrix[i][size] - sum) / matrix[i][i];
                }
            }
        } 
        flag = !isDiverged(result, temp, eps);
        if (flag)
            for (int i = 0; i < size; i++)
                result[i] = temp[i];
    }
    globalCount = count;
    return result;
}

// M���� ����������������� � �������������� ������������ ������
template <typename T>
vector<T> parallelCyclesCalculate(vector<vector<T>> matrix)
{
    int size = matrix.size();
    vector<T> result(size, 0.0);
    vector<T> temp(size, 0.0);
    int count = 0;
    for (bool flag = !isDiagonalDominanceBroken(matrix); flag; count++)
    {
#pragma omp parallel for
        for (int i = 0; i < size; i++)
        {
            T sum = 0.0;
            {
#pragma omp parallel for
                for (int j = 0; j < size; j++)
                    if (i != j)
                        sum += matrix[i][j] * result[j];
                temp[i] = (matrix[i][size] - sum) / matrix[i][i];
            }
        }
        flag = !isDiverged(result, temp, eps);
        if (flag)
#pragma omp parallel for
        for (int i = 0; i < size; i++)
            result[i] = temp[i];
    }
    globalCount = count;
    return result;
}

// ���������������� �����
template <typename T>
vector<T> sequentialCalculate(vector<vector<T>> matrix)
{
	int size = matrix.size();
    vector<T> result(size, 0.0);
    vector<T> temp(size, 0.0);
    int count = 0;
    for (bool flag = !isDiagonalDominanceBroken(matrix); flag; count++)
    {
        for (int i = 0; i < size; i++)
        {
            T sum = 0.0;
            for (int j = 0; j < size; j++)
                if (i != j)
                    sum += matrix[i][j] * result[j];
            temp[i] = (matrix[i][size] - sum) / matrix[i][i];
        }
        flag = !isDiverged(result, temp, eps);
        if (flag)
            for (int i = 0; i < size; i++)
                result[i] = temp[i];
    }
    globalCount = count;
    return result;
}
// �������� ���������� �������� �� ����������������� ����������
template <typename T>
T averageDeviationCalculate(vector<vector<T>> matrix, vector<T> result)
{
    int size = matrix.size();
    T deviage = 0.0;
    for (int i = 0; i < size; i++)
    {
        T sum = 0.0;
        for (int j = 0; j < size; j++)
            sum += matrix[i][j] * result[j];
        deviage += sum - matrix[i][size];
    }
    return deviage/size;
}
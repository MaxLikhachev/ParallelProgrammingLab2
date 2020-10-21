#pragma once
#include <iostream>
#include <vector>
#include <cmath>
#include <omp.h>

using namespace std;

const double accuracy = 0.05;
// ѕоследовательный метод
template <typename T>
vector<T> sequentialCalculate(vector<vector<T>> array)
{
	int size = array.size();
	vector<T> result(size, 0.0);
	for (int i = 0; i < size; i++)
		result[i] = array[i][size] / array[i][i];
	bool flag = true;

	for (int k = 0; flag; k++)
	{
		vector<T> temp = result;

		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				if (j == i)
					j++;
				temp[i] += array[i][j] / array[i][i] * result[i];
			}
			temp[i] = array[i][size] / array[i][i] - temp[i];
		}

		for (int i = 0; i < size; i++)
			if (abs(temp[i] - result[i]) > accuracy)
				flag = false;
		result = temp;
	}
	return result;
}
// ѕроверка отклонений значений от последовательного вычислени€
template <typename T>
T averageDeviationCalculate(vector<vector<T>> array, vector<T> result)
{
	int size = array.size();
	T controlSum = 0.0;
	int controlCounter = 0;
	vector<T>controlArray(size, 0.0);
	controlArray = sequentialCalculate(array);

	for (int i = 0; i < size; i++, controlCounter++)
		controlSum += controlArray[i] - result[i];

	return controlSum / controlCounter;
}
// ѕроверка корректности решени€ методом подстановки
template <typename T>
bool check(vector<vector<T>> array, vector<T> result)
{
	int size = array.size();
	bool flag = true;
	for (int i = 0; i < size; i++)
	{
		T sum = 0.0;
		for (int j = 0; j < size; j++)
			sum += array[i][j] * result[j];
		if (sum != array[i][size])
			flag = false;
		cout << "Checking [" << i << "] : calculated: " << sum << " expected: " << array[i][size] << endl;
	}
	return flag;
}
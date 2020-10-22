#pragma once

#include <iostream>
#include <vector>
#include <ctime>
#include <random>

#include "Display.h"

using namespace std;

template <typename T>
vector<vector<T>> init(int depth, T min, T max)
{
	minstd_rand rand(clock());
	uniform_int_distribution<> distribution(min, max);

	int width = depth + 1;
	vector<vector<T>>matrix(depth, vector<T>(width, 0.0));
	vector<T>solution(depth, 0.0);

	
	for (int i = 0; i < depth; i++)
		for (int j = 0; j < depth; j++)
			matrix[i][j] = distribution(rand);

	for (int i = 0; i < depth; i++)
	{
		int fabsSum = 0;
		for (int j = 0; j < depth; j++)
			if (j != i)
				fabsSum += fabs(matrix[i][j]);
		while(fabs(matrix[i][i]) < fabsSum)
			matrix[i][i] += distribution(rand);
	}
		
	for (int i = 0; i < depth; i++)
		solution[i] = distribution(rand);

	for (int i = 0; i < depth; i++)
	{
		double sum = 0.0;
		for (int j = 0; j < depth; j++)
			sum += matrix[i][j] * solution[j];
		matrix[i][depth] = sum;
	}
	return matrix;
}
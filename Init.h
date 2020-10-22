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
	vector<vector<T>>array(depth, vector<T>(width, 0.0));
	vector<T>solution(depth, 0.0);

	
	for (int i = 0; i < depth; i++)
		for (int j = 0; j < depth; j++)
			array[i][j] = distribution(rand);

	for (int i = 0; i < depth; i++)
	{
		int fabsSum = 0;
		for (int j = 0; j < depth; j++)
			if (j != i)
				fabsSum += fabs(array[i][j]);
		while(fabs(array[i][i]) < fabsSum)
			array[i][i] += distribution(rand);
	}
		
	for (int i = 0; i < depth; i++)
		solution[i] = distribution(rand);

	for (int i = 0; i < depth; i++)
	{
		double sum = 0.0;
		for (int j = 0; j < depth; j++)
			sum += array[i][j] * solution[j];
		array[i][depth] = sum;
	}

	display(array);

	return array;
}
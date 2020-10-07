#pragma once

#include <iostream>
#include <vector>
#include <ctime>
#include <random>

using namespace std;

template <typename T>
vector<vector<T>> random(int size, T min, T max)
{
	minstd_rand rand(clock());
	uniform_int_distribution<> distribution(min, max);

	vector<vector<T>>array(size, vector<T>(size + 1, 0.0));

	for (int i = 0; i < array.size(); i++)
		for (int j = 0; j < array[i].size(); j++)
			array[i][j] = distribution(rand);

	return array;
}

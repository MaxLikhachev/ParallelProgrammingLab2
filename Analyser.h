#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

#include "TestTypes.h"

using namespace std;

template <typename T>
void analyse(vector<vector<T>> array, vector<TestTypes> types) {
	cout << "\nAnalysys:\n";
	vector<T>averages(array.size(), 0.0);

	for (int i = 0; i < array.size(); i++)
	{
		cout << getTestType(types[i]) << " test:";
		auto minmax = minmax_element(array[i].begin(), array[i].end());
		cout << " Min: " << *minmax.first;
		cout << " Max: " << *minmax.second;
		T average = (*minmax.first + *minmax.second) / array[i].size();
		cout << " Avg: " << average << endl;
		averages[i] = average;
	}

	cout << "\nConclusion:\n";
	cout << "Best method: " << getTestType(types[min_element(averages.begin(), averages.end()) - averages.begin()]) << " (" << *min_element(averages.begin(), averages.end()) << ")\n";
	cout << "Worst method: " << getTestType(types[max_element(averages.begin(), averages.end()) - averages.begin()]) << " (" << *max_element(averages.begin(), averages.end()) << ")\n\n";
}
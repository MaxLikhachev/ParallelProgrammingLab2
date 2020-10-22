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
		getTestType(types[i]);
		cout << " test:";
		auto minmax = minmax_element(array[i].begin(), array[i].end());
		cout << " Min: " << *minmax.first;
		cout << " Max: " << *minmax.second;
		T average = (*minmax.first + *minmax.second) / 2.0;
		cout << " Avg: " << average << endl;
		averages[i] = average;
	}

	cout << "\nConclusion:\n";
	cout << "Best method: "; 
	getTestType(types[min_element(averages.begin(), averages.end()) - averages.begin()]);
	cout << " (" << *min_element(averages.begin(), averages.end());
	cout << ")\nWorst method: ";
	getTestType(types[max_element(averages.begin(), averages.end()) - averages.begin()]);
	cout << " (" << *max_element(averages.begin(), averages.end()) << ")\n\n";
}
#pragma once
#include <iostream>
#include <vector>

using namespace std;

template <typename T>
void display(vector<vector<T>> array)
{
	for (int i = 0; i < array.size(); i++)
	{
		for (int j = 0; j < array[i].size(); j++)
			cout << array[i][j] << " ";
		cout << endl;
	}
	cout << endl;
}

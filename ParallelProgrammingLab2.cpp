#include <iostream>
#include <vector>
#include <omp.h>

#include "Init.h"
#include "Display.h"
#include "Test.h"
#include "TestTypes.h"

using namespace std;

int main()
{
    int size = 0;

    cout << "Matrix size: ";
    cin >> size;

    cout << "Generate matrix... ";
    vector<vector<double>> matrix(size, vector<double>(size, 0.0));
    matrix = init(size, -100.0, 100.0);
    cout << "successfully\n";
    
    int count = 0;
    cout << "Tests count: ";
    cin >> count;

    vector<TestTypes> types = { TestTypes::SEQUENTIAL};
    tests(matrix, types, count);
}
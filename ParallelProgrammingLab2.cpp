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

    cout << "Enter arrays size:\n";
    cin >> size;
    cout << "Arrays size: " << size << endl << endl;

    cout << "Generating array...\n";
    vector<vector<double>> array(size, vector<double>(size, 0.0));
    array = random(size, 0.0, 100.0);

    array[0][0] = -19.0, array[0][1] = 2.0, array[0][2] = -1.0, array[0][3] = -8.0, array[0][4] = 38.0;
    array[1][0] = 2.0, array[1][1] = 14.0, array[1][2] = 0.0, array[1][3] = -4.0, array[1][4] = 20.0;
    array[2][0] = 6.0, array[2][1] = -5.0, array[2][2] = -20.0, array[2][3] = -6.0, array[2][4] = 52.0;
    array[3][0] = -6.0, array[3][1] = 4.0, array[3][2] = -2.0, array[3][3] = 15.0, array[3][4] = 43.0;

    int count = 0;
    cout << "Enter tests count:\n";
    cin >> count;
    cout << "Tests count: " << count << endl << endl;

    vector<TestTypes> types = { TestTypes::SEQUENTIAL};
    tests(array, types, count);

    // Iter(0.0);
}
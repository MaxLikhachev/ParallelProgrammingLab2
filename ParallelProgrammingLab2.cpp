#include <iostream>
#include <vector>
#include <omp.h>

#include "Display.h"
#include "Test.h"
#include "TestTypes.h"
#include "TestMethod.h"

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
    display(array);
    cout << "Array generated\n\n";

    int count = 0;
    cout << "Enter tests count:\n";
    cin >> count;
    cout << "Tests count: " << count << endl << endl;

    vector<TestTypes> types = { TestTypes::SEQUENTIAL};
    tests(array, types, count);

    Iter(0.0);
}
#pragma once
#include <string>
#include <iostream>

using namespace std;

enum class TestTypes
{
    SEQUENTIAL,
    PARALLEL_CYCLES,
    PARALLEL_SECTIONS,
    PARALLEL_ALGORITHM,
};

template<typename T>
void getTestType(T index)
{
    switch (index)
    {
    case TestTypes::SEQUENTIAL: cout << "Sequential method"; break;
    case TestTypes::PARALLEL_CYCLES: cout << "Parallel with cycles method"; break;
    case TestTypes::PARALLEL_SECTIONS: cout << "Parallel with sections method"; break;
    case TestTypes::PARALLEL_ALGORITHM: cout << "Parallel with algorithm method"; break;
    default: cout << "Unknown method";
    }
}
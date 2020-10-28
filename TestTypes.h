#pragma once
#include <string>
#include <iostream>

using namespace std;

enum class TestTypes
{
    SEQUENTIAL,
    PARALLEL_CYCLES,
};

template<typename T>
void getTestType(T index)
{
    switch (index)
    {
    case TestTypes::SEQUENTIAL: cout << "Sequential method"; break;
    case TestTypes::PARALLEL_CYCLES: cout << "Parallel with cycles method"; break;
    default: cout << "Unknown method";
    }
}
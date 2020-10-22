#pragma once
#include <string>
#include <iostream>

using namespace std;

enum class TestTypes
{
    SEQUENTIAL,
};

template<typename T>
void getTestType(T index)
{
    switch (index)
    {
    case TestTypes::SEQUENTIAL: cout << "Sequential method"; break;
    default: cout << "Unknown method";
    }
}
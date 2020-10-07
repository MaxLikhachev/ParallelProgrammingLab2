#pragma once
#include <string>

enum class TestTypes
{
    SEQUENTIAL,
};

template<typename T>
string getTestType(T index)
{
    switch (index)
    {
    case TestTypes::SEQUENTIAL: return "Sequential method"; break;
    default: return "Unknown method";
    }
}
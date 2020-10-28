/*
Написать программу с использованием технологии OpenMP, которая решает поставленную задачу. Отчет должен содержать:
Постановку задачи,
Краткое описание метода решения,
Программную реализацию,
Анализ эффективности вычислительных экспериментов для различной размерности задачи.

Программная реализация должна включать:
Последовательное решение,
Вариант распараллеливания с использованием параллельных циклов (если возможно),
Вариант распараллеливания c использованием таких средств распараллеливания, как параллельные, критические секции и др.,
Вариант распараллеливания c использованием алгоритмов для параллельной обработки.

Разработать программу для решения систем линейных уравнений методом простой итерации.
*/


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
    matrix = init(size, -size * 1.0, size * 1.0);
    cout << "successfully\n";
    
    int count = 0;
    cout << "Tests count: ";
    cin >> count;

    vector<TestTypes> types = { TestTypes::SEQUENTIAL, TestTypes::PARALLEL_CYCLES, TestTypes::PARALLEL_SECTIONS, TestTypes::PARALLEL_ALGORITHM };
    tests(matrix, types, count);
}
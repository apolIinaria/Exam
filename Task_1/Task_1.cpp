#include <iostream>
#include <cmath>
using namespace std;

const int array_size = 5;

double sumOfPositives(const double array[], int size) 
{
    double sum = 0.0;
    for (int i = 0; i < size; ++i) 
    {
        if (array[i] > 0) 
        {
            sum += array[i];
        }
    }
    return sum;
}

int findMaxAbs(const double array[], int size) 
{
    int maxIndex = 0;
    for (int i = 1; i < size; ++i) 
    {
        if (abs(array[i]) > abs(array[maxIndex])) 
        {
            maxIndex = i;
        }
    }
    return maxIndex;
}

int findMinAbs(const double array[], int size) 
{
    int minIndex = 0;
    for (int i = 1; i < size; ++i) 
    {
        if (abs(array[i]) < abs(array[minIndex])) 
        {
            minIndex = i;
        }
    }
    return minIndex;
}

double multiplication(const double array[], int startIndex, int endIndex) 
{
    double product = 1.0;
    for (int i = startIndex + 1; i < endIndex; ++i) 
    {
        product *= array[i];
    }
    return product;
}

void sort(double array[], int size) 
{
    for (int i = 0; i < size - 1; ++i) 
    {
        for (int j = 0; j < size - i - 1; ++j) 
        {
            if (array[j] < array[j + 1]) 
            {
                swap(array[j], array[j + 1]);
            }
        }
    }
}

int main() 
{
    double array[array_size];

    cout << "Введіть елементи масиву: ";
    for (int i = 0; i < array_size; ++i) 
    {
        cin >> array[i];
    }

    double positiveSum = sumOfPositives(array, array_size);
    cout << "Сума додатних елементів: " << positiveSum << "\n";

    int maxAbsIndex = findMaxAbs(array, array_size);
    int minAbsIndex = findMinAbs(array, array_size);
    double product = multiplication(array, min(maxAbsIndex, minAbsIndex), max(maxAbsIndex, minAbsIndex));
    cout << "Добуток елементів між максимальним і мінімальним за модулем: " << product << "\n";

    sort(array, array_size);

    cout << "Відсортований масив за спаданням: ";
    for (int i = 0; i < array_size; ++i) 
    {
        cout << array[i] << " ";
    }
    cout << "";

    return 0;
}

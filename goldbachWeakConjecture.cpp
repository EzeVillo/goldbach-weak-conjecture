#include <iostream>
#include <array>

using namespace std;

#define smallestPrimeNumber 2

bool isPrimeNumber(int);
array<int, 3> goldbachWeakConjecture(int);

int main()
{
    for (int i = 7; i < 1000; i = i + 2)
    {
        array<int, 3> solution;
        solution = goldbachWeakConjecture(i);
        cout << i << " = " << solution[0] << " + " << solution[1] << " + " << solution[2] << endl;
    }
}

bool isPrimeNumber(int number)
{
    if (number < smallestPrimeNumber)
        return false;

    for (int i = smallestPrimeNumber; i < number; i++)
        if (number % i == 0)
            return false;

    return true;
}

array<int, 3> goldbachWeakConjecture(int number)
{
    if (number < 7)
        throw range_error("number must not be less than 7.");

    if (number % 2 == 0)
        throw invalid_argument("number must not be even.");

    for (int i = smallestPrimeNumber; i <= number - smallestPrimeNumber * 2; i++)
        if (isPrimeNumber(i))
            for (int j = smallestPrimeNumber; j <= number - i - smallestPrimeNumber; j++)
                if (isPrimeNumber(j) && isPrimeNumber(number - i - j))
                    return {i, j, number - i - j};

    throw bad_exception();
}
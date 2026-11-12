// Lab 6.1.it
// Variant 13

#include <iostream>
#include <time.h>
#include <iomanip>

using namespace std;

void Create(int* p, const int size, const int Low, const int High) {
    for (int i = 0; i < size; i++)
        p[i] = Low + rand() % (High - Low + 1);
}

void Print(int* p, const int size)
{
    for (int i = 0; i < size; i++)
        cout << setw(4) << p[i];
    cout << endl;
}

// Критерій: елемент додатний або має парний індекс
int Sum(int* p, const int size, int& count) {
    int S = 0;
    count = 0;
    for (int i = 0; i < size; i++)
        if (p[i] > 0 || i % 2 == 0) {
            S += p[i];
            p[i] = 0;
            count++;
        }
    return S;
}

int main() {

    srand((unsigned)time(NULL));

    const int size = 24;
    int p[size];

    int Low = -10;
    int High = 14;

    Create(p, size, Low, High);
    cout << "Original array: ";
    Print(p, size);
    cout << endl;

    int count = 0;
    int sum = Sum(p, size, count);

    cout << "Count of the elements: " << count << endl;
    cout << "Sum of the elements: " << sum << endl;

    cout << endl;
    cout << "Modified array: ";
    Print(p, size);

    return 0;
}
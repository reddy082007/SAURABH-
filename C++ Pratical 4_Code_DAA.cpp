#include <iostream>
#include <chrono>
using namespace std;
using namespace chrono;

// Iterative Factorial
unsigned long long factorialIterative(int n) {
    unsigned long long fact = 1;

    for (int i = 1; i <= n; i++)
        fact *= i;

    return fact;
}

// Recursive Factorial
unsigned long long factorialRecursive(int n) {
    if (n <= 1)
        return 1;

    return n * factorialRecursive(n - 1);
}

int main() {
    int n;

    cout << "Enter a number: ";
    cin >> n;

    // Iterative
    auto start = high_resolution_clock::now();
    unsigned long long result1 = factorialIterative(n);
    auto stop = high_resolution_clock::now();

    cout << "\nIterative Factorial = " << result1 << endl;
    cout << "Time = "
         << duration_cast<nanoseconds>(stop - start).count()
         << " ns\n";

    // Recursive
    start = high_resolution_clock::now();
    unsigned long long result2 = factorialRecursive(n);
    stop = high_resolution_clock::now();

    cout << "\nRecursive Factorial = " << result2 << endl;
    cout << "Time = "
         << duration_cast<nanoseconds>(stop - start).count()
         << " ns\n";

    return 0;
}
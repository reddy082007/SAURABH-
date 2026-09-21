#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
using namespace std;
using namespace chrono;

// Bubble Sort
void bubbleSort(vector<int>& a) {
    for (int i = 0; i < a.size() - 1; i++)
        for (int j = 0; j < a.size() - i - 1; j++)
            if (a[j] > a[j + 1])
                swap(a[j], a[j + 1]);
}

// Selection Sort
void selectionSort(vector<int>& a) {
    for (int i = 0; i < a.size() - 1; i++) {
        int min = i;
        for (int j = i + 1; j < a.size(); j++)
            if (a[j] < a[min])
                min = j;
        swap(a[i], a[min]);
    }
}

// Insertion Sort
void insertionSort(vector<int>& a) {
    for (int i = 1; i < a.size(); i++) {
        int key = a[i];
        int j = i - 1;

        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}

// Merge Sort
void mergeSort(vector<int>& a, int l, int r) {
    if (l >= r) return;

    int m = (l + r) / 2;
    mergeSort(a, l, m);
    mergeSort(a, m + 1, r);

    vector<int> temp;
    int i = l, j = m + 1;

    while (i <= m && j <= r) {
        if (a[i] < a[j])
            temp.push_back(a[i++]);
        else
            temp.push_back(a[j++]);
    }

    while (i <= m) temp.push_back(a[i++]);
    while (j <= r) temp.push_back(a[j++]);

    for (int k = 0; k < temp.size(); k++)
        a[l + k] = temp[k];
}

// Quick Sort
void quickSort(vector<int>& a, int low, int high) {
    if (low >= high) return;

    int pivot = a[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (a[j] < pivot)
            swap(a[++i], a[j]);
    }

    swap(a[i + 1], a[high]);
    int p = i + 1;

    quickSort(a, low, p - 1);
    quickSort(a, p + 1, high);
}

int main() {
    int n = 100;
    vector<int> arr(n);

    // Generate random numbers
    for (int i = 0; i < n; i++)
        arr[i] = rand() % 1000;

    cout << "Number of Elements = " << n << "\n\n";

    vector<int> temp;
    auto start = high_resolution_clock::now();
    temp = arr;
    bubbleSort(temp);
    auto stop = high_resolution_clock::now();
    cout << "Bubble Sort    : "
         << duration_cast<microseconds>(stop - start).count()
         << " microseconds\n";

    start = high_resolution_clock::now();
    temp = arr;
    selectionSort(temp);
    stop = high_resolution_clock::now();
    cout << "Selection Sort : "
         << duration_cast<microseconds>(stop - start).count()
         << " microseconds\n";

    start = high_resolution_clock::now();
    temp = arr;
    insertionSort(temp);
    stop = high_resolution_clock::now();
    cout << "Insertion Sort : "
         << duration_cast<microseconds>(stop - start).count()
         << " microseconds\n";

    start = high_resolution_clock::now();
    temp = arr;
    mergeSort(temp, 0, n - 1);
    stop = high_resolution_clock::now();
    cout << "Merge Sort     : "
         << duration_cast<microseconds>(stop - start).count()
         << " microseconds\n";

    start = high_resolution_clock::now();
    temp = arr;
    quickSort(temp, 0, n - 1);
    stop = high_resolution_clock::now();
    cout << "Quick Sort     : "
         << duration_cast<microseconds>(stop - start).count()
         << " microseconds\n";

    return 0;
}
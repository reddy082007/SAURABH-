#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>

using namespace std;
using namespace chrono;

// Max Heapify
void maxHeapify(vector<int>& a, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && a[left] > a[largest])
        largest = left;

    if (right < n && a[right] > a[largest])
        largest = right;

    if (largest != i) {
        swap(a[i], a[largest]);
        maxHeapify(a, n, largest);
    }
}

// Max Heap Sort
void maxHeapSort(vector<int>& a) {
    int n = a.size();

    for (int i = n / 2 - 1; i >= 0; i--)
        maxHeapify(a, n, i);

    for (int i = n - 1; i > 0; i--) {
        swap(a[0], a[i]);
        maxHeapify(a, i, 0);
    }
}

// Min Heapify
void minHeapify(vector<int>& a, int n, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && a[left] < a[smallest])
        smallest = left;

    if (right < n && a[right] < a[smallest])
        smallest = right;

    if (smallest != i) {
        swap(a[i], a[smallest]);
        minHeapify(a, n, smallest);
    }
}

// Min Heap Sort
void minHeapSort(vector<int>& a) {
    int n = a.size();

    for (int i = n / 2 - 1; i >= 0; i--)
        minHeapify(a, n, i);

    for (int i = n - 1; i > 0; i--) {
        swap(a[0], a[i]);
        minHeapify(a, i, 0);
    }

    reverse(a.begin(), a.end());
}

int main() {
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> a(n);

    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++)
        cin >> a[i];

    vector<int> maxArray = a;
    vector<int> minArray = a;

    // Max Heap Sort
    auto start = high_resolution_clock::now();

    maxHeapSort(maxArray);

    auto stop = high_resolution_clock::now();

    cout << "\nMax Heap Sort: ";
    for (int x : maxArray)
        cout << x << " ";

    cout << "\nTime: "
         << duration_cast<microseconds>(stop - start).count()
         << " microseconds\n";

    // Min Heap Sort
    start = high_resolution_clock::now();

    minHeapSort(minArray);

    stop = high_resolution_clock::now();

    cout << "\nMin Heap Sort: ";
    for (int x : minArray)
        cout << x << " ";

    cout << "\nTime: "
         << duration_cast<microseconds>(stop - start).count()
         << " microseconds\n";

    return 0;
}
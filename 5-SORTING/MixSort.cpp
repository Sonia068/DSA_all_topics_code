#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
using namespace std;

int insertionSort(int arr[], int n, int &shifts) {
    int comparisons = 0;
    shifts = 0; // Initialize shifts

    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            comparisons++;
            arr[j + 1] = arr[j]; // Shift
            shifts++;
            j--;
        }
        if (j >= 0) comparisons++;
        arr[j + 1] = key; // Insert key (count as shift)
        shifts++;
    }
    return comparisons;
}

int shellSort(int arr[], int n, int &shifts) {
    int comparisons = 0;
    shifts = 0; // Initialize shifts

    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                comparisons++;
                arr[j] = arr[j - gap]; // Shift
                shifts++;
            }
            if (j >= gap) comparisons++; // For failed comparison
            arr[j] = temp; // Insert temp (count as shift)
            shifts++;
        }
    }
    return comparisons;
}

int getMax(int arr[], int n) {
    int mx = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}

int countRadixSortOps(int arr[], int n) {
    int output[n];
    int maxVal = getMax(arr, n);
    int passes = 0;

    for (int exp = 1; maxVal / exp > 0; exp *= 10) {
        int count[10] = {0};
        passes++;  // Each digit-level pass is counted

        for (int i = 0; i < n; i++)
            count[(arr[i] / exp) % 10]++;

        for (int i = 1; i < 10; i++)
            count[i] += count[i - 1];

        for (int i = n - 1; i >= 0; i--) {
            output[count[(arr[i] / exp) % 10] - 1] = arr[i];
            count[(arr[i] / exp) % 10]--;
        }

        for (int i = 0; i < n; i++)
            arr[i] = output[i];
    }

    // Approximate comparisons as: passes × n
    return passes * n;
}

int main() {
    string filename;
    cout << "Enter the filename (e.g., 100.txt): ";
    cin >> filename;

    ifstream file(filename);
    if (!file) {
        cerr << "Error: File not found or could not be opened.\n";
        return 1;
    }

    int original[100000];
    int size = 0;

    while (file >> original[size]) {
        size++;
    }
    file.close();

    // Arrays for each sort to keep original intact
    int arr1[100000], arr2[100000], arr3[100000];
    for (int i = 0; i < size; i++) {
        arr1[i] = original[i];
        arr2[i] = original[i];
        arr3[i] = original[i];
    }

    int insertionShifts = 0, shellShifts = 0;
    int insertionComparisons = insertionSort(arr1, size, insertionShifts);
    int shellComparisons = shellSort(arr2, size, shellShifts);
    int radixApproxComparisons = countRadixSortOps(arr3, size);

    cout << " File: " << filename << endl;
    cout << " Size: " << size << "\n" << endl;

    cout << "Insertion Sort Comparisons: " << insertionComparisons << endl;
    cout << "Insertion Sort Shifts:      " << insertionShifts << endl;

    cout << "Shell Sort Comparisons:     " << shellComparisons << endl;
    cout << "Shell Sort Shifts:          " << shellShifts << endl;

    cout << "Radix Sort Work Estimate:   " << radixApproxComparisons << " (passes size)" << endl;

    return 0;
}

// COUNT SORT :
#include <iostream>
using namespace std;

void count_sort(int a[], int n, int k) {
    int count[k+1] = {0};   // frequency array  // count from 0 that's why 
    int b[n];               // output array

    // Step 1: Count frequencies
    for (int i = 0; i < n; i++) {
        count[a[i]]++;
    }

    // Step 2: Cumulative sum
    for (int i = 1; i <= k; i++) {
        count[i] =count[i]+count[i-1];
    }

    // Step 3: Build output array (stable sort)
    for (int i = n-1; i >= 0; i--) {
        b[--count[a[i]]] = a[i];
    }

    // Step 4: Copy sorted values back into original array
    for (int i = 0; i < n; i++) {
        a[i] = b[i];
    }
}

void display(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Find maximum element (needed for k)
    int k = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > k) k = arr[i];
    }

    cout << "Before Count Sort:" << endl;
    display(arr, n);

    count_sort(arr, n, k);

    cout << "After Count Sort:" << endl;
    display(arr, n);

    return 0;
}



/*Given an array arr[] of daily stock prices, the stock span for the
i-th day is the count of consecutive days up to and including day
i, such that each of those days had a stock price less than or equal
to the price on day i.*/

// without using stack (O(n^2) -> time complexity)

#include <iostream>
using namespace std;

void stockSpan(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        int count = 1; 
        for (int j = i - 1; j >= 0 && arr[j] <= arr[i]; j--) {
            count++;
        }
        cout << count << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter the size of the array:" << endl;
    cin >> n;

    int arr[100];
    cout << "Enter the array elements:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    stockSpan(arr, n);

    return 0;
}


/*Given an array arr[] of daily stock prices, the stock span for the
i-th day is the count of consecutive days up to and including day
i, such that each of those days had a stock price less than or equal
to the price on day i.*/

//  using stack (O(n) -> time complexity)

#include <iostream>
#include <stack>
using namespace std;

void stockSpanStack(int arr[], int n) {
    stack<int>s;
    int span[100];
    for(int i=0;i<n;i++){
        while(!s.empty() && arr[s.top()]<=arr[i]){
            s.pop();
        }

        if(s.empty()){
            span[i]=i+1;
        }
        else{
            span[i]=i-s.top();
        }
        s.push(i);
    }

        for(int i=0;i<n;i++){
            cout<<span[i]<<" ";
        }

       cout<<endl;
    }
  
int main() {
    int n;
    cout << "Enter number of days: ";
    cin >> n;

    int arr[100];
    cout << "Enter stock prices: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Stock spans: ";
    stockSpanStack(arr, n);

    return 0;
}
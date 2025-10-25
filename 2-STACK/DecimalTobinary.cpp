//Construct a C++ code to convert a given decimal number into binary using stack.
#include <iostream>
#include <stack>
using namespace std;

void decToBin(int number) {
    stack<int> s;

    while (number > 0) {
        int remainder = number % 2;
        s.push(remainder);
        number = number / 2;
    }

    cout << "Binary number: ";
    while (!s.empty()) {
        cout << s.top();
        s.pop();
    }
    cout << endl;
}

int main() {
    int number;
    cout << "Enter decimal number: ";
    cin >> number;

    if (number == 0) {
        cout << "Binary: 0" << endl;
    } else {
        decToBin(number);
    }

    return 0;
}





// this function uses power method (which is scalable)

// void decTobin(int arr[],int n,int number){
//     stack <int>s;
//     stack <int> s1;
//     for(int i=0;i<n;i++){
//         if(number>=arr[i]){
//             s.push(1);
//             number=number-arr[i];
//         }

//         else{
//             s.push(0);
//         }
//     }

//     while(!s.empty()){
//          int data=s.top();
//            s1.push(data);
//            s.pop();
//     }

//     cout<<"After converting decimal number into Binary:"<<endl;
//     while(!s1.empty()){
//         cout<<s1.top()<<" ";
//         s1.pop();
//     }
    

// }




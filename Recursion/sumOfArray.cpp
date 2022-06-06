#include<iostream>
using namespace std;

int sumOfArray(int arr[], int n){
    if(n==0) {
        return arr[0];
    }
    return arr[n]+sumOfArray(arr, n-1);
}

int main() {
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++) {
        cin>>arr[i];
    }
    cout<<"Sum : "<<sumOfArray(arr, n-1)<<endl;
    return 0;
}
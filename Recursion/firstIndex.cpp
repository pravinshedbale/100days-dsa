#include<iostream>
using namespace std;

int firstIndex(int arr[], int size, int n) {
    if(arr[size]==n) {
        return size;
    }
    return firstIndex(arr, size-1, n);
}


int main() {
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++) {
        cin>>arr[i];
    }
    int x;
    cin>>x;
    cout<<firstIndex(arr, n-1, x)<<endl;
    return 0;
}
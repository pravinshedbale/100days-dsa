#include<iostream>
using namespace std;

bool checkNumber(int arr[], int size, int x) {
    if(arr[size]==x) {
        return true;
    }
    if(size==-1) {
        return false;
    }
    return checkNumber(arr, size-1, x);
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
    cout<<checkNumber(arr, n-1, x)<<endl;
    return 0;
}
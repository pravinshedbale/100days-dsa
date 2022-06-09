#include<iostream>
using namespace std;
#include<iostream>
using namespace std;

// Enhanced version of the bubble sort
void selectionSort(int *arr, int n) {
    int minIndex=0;
    for(int i=0; i<n-1; i++) {
        minIndex=i;
        for(int j=i+1; j<n; j++) {
            if(arr[j]<arr[i]) {
                minIndex=j;
            }
        }
        int temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
    }
}

int main() {
    int n;
    cin>>n;

    int *arr = new int[n];

    for(int i=0; i<n; i++) {
        cin>>arr[i];
    }

    selectionSort(arr, n);

    for(int i=0; i<n; i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}
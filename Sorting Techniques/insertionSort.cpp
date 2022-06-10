#include<iostream>
using namespace std;

// Enhanced version of the insertion sort
void insertionSort(int *arr, int n) {
    int swap = 1; //This flag is used to skip passes if there is no swap in previous pass
    for(int i=0; i<n && swap==1; i++) {
        cout<<"Pass : "<<i<<endl;
        swap=0;
        for(int j=0; j<n-i-1; j++) {
            if(arr[j]>arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                swap=1;
            }
        }
    }
}

int main() {
    int n;
    cin>>n;

    int *arr = new int[n];

    for(int i=0; i<n; i++) {
        cin>>arr[i];
    }

    insertionSort(arr, n);

    for(int i=0; i<n; i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}
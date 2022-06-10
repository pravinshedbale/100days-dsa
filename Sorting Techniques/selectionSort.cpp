#include<iostream>
using namespace std;
#include<iostream>
using namespace std;

// Enhanced version of the bubble sort
void selectionSort(int *arr, int n) {
    int i, j, temp;
    for(int i=1; i<n; i++) {
        temp = arr[i];
        j=i;
        while(arr[j-1]>temp && j>=1) {
            arr[j] = arr[j-1];
            j--;
        }
        arr[j] = temp;
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
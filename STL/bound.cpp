#include<iostream>
#include<algorithm>
using namespace std;

int main() {
    int n=7;
    int arr[] = {1,3,2,5,3,7,6};
    cout<<"Lower Bound : ";
    cout<<lower_bound(arr, arr+7, 4)-arr<<endl;

    cout<<"Upper Bound : ";
    cout<<upper_bound(arr, arr+7, 5)-arr<<endl;

    int a[] ={1,2,3,4,5,6,1,2};
    cout<<upper_bound(a, a+8, 1)<<endl; 
    return 0;
}
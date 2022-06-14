#include <iostream>
using namespace std;
void printLeaders(int arr[], int size)
{
	int max_from_right = arr[size-1];
	cout << max_from_right << " ";
	
	for (int i = size-2; i >= 0; i--)
	{
		if (max_from_right < arr[i])
		{		
			max_from_right = arr[i];
			cout << max_from_right << " ";
		}
	}
}
int main()
{
    int n;
    cin>>n;
    int *arr = new int[n];
    for(int i=0; i<n; i++) {
        cin>>arr[i];
    }
	printLeaders(arr, n);
	return 0;
}

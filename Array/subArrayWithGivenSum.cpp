#include<iostream>
#include<vector>
using namespace std;
vector<int> subarraySum(int arr[], int n, long long s) {
        vector<int> ans;
        vector<int> noFound;
        noFound.push_back(-1);
        long long sum = 0;
        int right = 0;
        for(int i=0; i<n; i++) {
            sum += arr[i];
            while(sum>s) {
                sum-=arr[right++];
            }
            if(sum==s) {
                ans.push_back(right+1);
                ans.push_back(i+1);
                return ans;
            }
        }
        return noFound;
    }

int main() {
    int n, s;
    cin>>n;
    int arr[n];
    cin>>s;
    for(int i=0; i<n; i++) {
        cin>>arr[i];
    }
    vector<int> ans = subarraySum(arr, n, s);
    for(int i=0; i<ans.size(); i++) {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}
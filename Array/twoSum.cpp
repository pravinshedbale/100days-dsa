#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> solution;
    unordered_map<int, int> mp;
    for(int i=0;i<nums.size();i++) {
        if (mp.find(target-nums[i]) != mp.end()) {
            solution.push_back(mp[target-nums[i]]);
            solution.push_back(i);
            return solution;
        }
        mp[nums[i]]=i;
    }
    return solution;
}

int main() {
    int n;
    cin>>n;
    vector<int> v;  
    for(int i=0; i<n; i++) {
        int val;
        cin>>val;
        v.push_back(val);
    }
    int target;
    cin>>target;
    vector<int> ans = twoSum(v, target);

    for(int i=0; i<ans.size(); i++) {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}
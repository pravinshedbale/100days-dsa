#include<iostream>
#include<set>
#include<vector>
using namespace std;

vector<int> removeDuplicate(vector<int> v) {
    set<int> s;
    vector<int> op;
    for(int i=0; i<v.size(); i++) {
        if(s.find(v[i])==s.end()) {
            s.insert(v[i]);
            op.push_back(v[i]);
        }
    }
    return op;
}

int main() {
    vector<int> v;
    int n=5;
    while(n-- !=0 ) {
        int e;
        cin>>e;
        v.push_back(e);
    }
    vector<int> op = removeDuplicate(v);
    vector<int>::iterator it;

    for(it=op.begin(); it!=op.end(); it++) {
        cout<<*it<<" ";
    }
    cout<<endl;
    return 0;
}
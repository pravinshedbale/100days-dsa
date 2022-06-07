#include<iostream>
#include<map>
using namespace std;

int main() {
    int arr[6] = {1, 2, 3, 1, 2, 4};
    map<int,int> m;
    for(int i=0; i<6; i++) {
        m[arr[i]]++;
    }

    map<int, int>::iterator it;

    for(it=m.begin(); it!=m.end(); it++) {
        cout<<it->first<<" : "<<it->second<<endl;
    }
    return 0;
}
#include<iostream>
#include<vector>
using namespace std;

int main() {
    vector<int> v;
    for(int i=1; i<=5; i++) {
        v.push_back(i);
    }

    vector<int>::iterator it ;

    for(it=v.begin(); it!=v.end(); it++) {
        cout<< *it<<endl;
    }
    return 0;
}
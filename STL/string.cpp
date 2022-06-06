#include<iostream>
#include<string>
using namespace std;

int main() {
    string s = "Pravin Shedbale";

    string::reverse_iterator it;

    for(it=s.rbegin(); it!=s.rend(); it++) {
        cout<<*it;
    }
    cout<<endl;
    return 0;
}
#include<iostream>
#include<set>
using namespace std;

int main() {
    set<int> s;
    s.insert(10);
    s.insert(20);
    s.insert(30);
    set<int>::iterator it;

    for(it=s.begin(); it!=s.end(); it++) {
        cout<< *it<<endl;
    }
    if(s.find(110)!=s.end()) {
        cout<<"Found"<<endl;
    } else {
        cout<<"Not Found"<<endl;
    }
    return 0;
}
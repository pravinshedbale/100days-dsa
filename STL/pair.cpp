#include<iostream>
#include<utility>
using namespace std;

int main() {
    pair<int, int> p1;
    pair<int, char> p2;
    pair<char, char>p3;

    p1.first = 10;
    p1.second = 20;

    p2 = make_pair(10, 'A');

    p3 = make_pair('A', 'B');

    cout<<"Pair1 "<<"("<<p1.first<<", "<<p1.second<<")"<<endl;
    cout<<"Pair2 "<<"("<<p2.first<<", "<<p2.second<<")"<<endl;
    cout<<"Pair3 "<<"("<<p3.first<<", "<<p3.second<<")"<<endl;
    return 0;
}
#include<iostream>
using namespace std;

int numberOfDigits(int n) {
    if(n<=0) {
        return 0;
    }
    return 1+numberOfDigits(n/10);
}

int main() {
    int n;
    cin>>n;
    cout<<"Number of Digits : "<<numberOfDigits(n)<<endl;
    return 0;
}
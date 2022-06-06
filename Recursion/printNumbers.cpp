#include<iostream>
using namespace std;

void printNumbers(int n) {
    if(n==0) {
        return;
    }
    printNumbers(n-1);
    cout<<n<<endl;
}

int main() {
    int n;
    cin>>n;
    printNumbers(n);
    return 0;
}
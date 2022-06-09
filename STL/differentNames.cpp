#include<iostream>
#include<set>
#include<string>
#include<map>
using namespace std;
int main() {
    string s;
    getline(cin, s);
    int beg=0;
    int len = 0;
    map<string, int> m;
    for(int i=0; i<s.length(); i++) {
        if(s[i]==' ') {
            m[s.substr(beg, len)]++;
            beg = i+1;
            len = 0;
        }
        if(s[i+1]=='\0') {
            m[s.substr(beg, len)]++;
        }
        len++;
    }
    map<string, int>::iterator itr;
    int count=0;
    for(itr=m.begin(); itr!=m.end(); itr++) {
        if(itr->second > 1) {
            count++;
            cout<<itr->first<<" "<<itr->second<<endl;
        }
    }
    if(count==0) {
        cout<<-1;
    }
    return 0;
}
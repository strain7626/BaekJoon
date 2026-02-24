#include <bits/stdc++.h>

using namespace std;

int main() {
    int T;cin>>T;
    if (T==1) {
        long long A,B,C;cin>>A>>B;C=A+B;
        string res;
        for (int i=0;i<13;i++) res+=C%26+'a',C/=26;
        cout << res;
    } else {
        string req;cin>>req;
        long long res=0;
        for (int i=12;i>=0;i--) res*=26,res+=req[i]-'a';
        cout << res;
    } 
}
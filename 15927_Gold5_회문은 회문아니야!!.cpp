#include <bits/stdc++.h>

using namespace std;

int main() {
    string S;cin>>S;
    int N=S.size();

    bool b1=1,b2=1;
    for (int i=1;i<N;i++) if (S[0]!=S[i]) {b1=0;break;}
    for (int i=0;i<N/2;i++) if (S[i]!=S[N-i-1]) {b2=0;break;}

    cout<<(b1?-1:b2?N-1:N);
}
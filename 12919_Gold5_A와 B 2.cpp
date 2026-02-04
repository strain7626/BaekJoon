#include <bits/stdc++.h>

using namespace std;

bool Solve(string S,string T) {
    int s=S.size(),t=T.size();
    if (s==t) return S==T;
    if (T[t-1]=='A'&&Solve(S,T.substr(0,t-1))) return 1;
    reverse(T.begin(),T.end());
    if (T[t-1]=='B'&&Solve(S,T.substr(0,t-1))) return 1;
    return 0;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    string S,T;cin>>S>>T;
    cout<<Solve(S,T);
}
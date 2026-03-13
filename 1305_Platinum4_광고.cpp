#include <bits/stdc++.h>

using namespace std;

int L;
string S;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    cin>>L>>S;

    int cnt=0;
    vector<int> pi(L);pi[0]=0;
    for(int i=1;i<L;i++) {
        while(cnt&&S[i]!=S[cnt]) cnt=pi[cnt-1];
        if(S[i]==S[cnt]) cnt++;
        pi[i]=cnt;
    }

    cout<<L-pi.back();
}
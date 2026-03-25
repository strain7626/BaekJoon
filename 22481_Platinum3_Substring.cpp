#include <bits/stdc++.h>

using namespace std;
using ll=long long;

const int MXN=3e5+1;
const int M1=1e9+7;
const int M2=1e9+7;

ll N,M,H1[MXN],H2[MXN],p1[MXN]={1},p2[MXN]={1};
string S;
vector<pair<ll,ll>> chk;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    cin>>N>>M>>S;
    
    for(int i=0;i<N;i++) p1[i+1]=(p1[i]*29)%M1,H1[i+1]=(H1[i]+(S[i]-'a'+1)*p1[i])%M1;
    for(int i=0;i<N;i++) p2[i+1]=(p2[i]*31)%M2,H2[i+1]=(H2[i]+(S[i]-'a'+1)*p2[i])%M2;
    
    int l=0,r=1;
    chk.reserve(M);
    while(M--) {
        string cmd;cin>>cmd;
        if(cmd=="R++") chk.push_back({(H1[++r]-H1[l]+M1)%M1*p1[N-l]%M1,(H2[r]-H2[l]+M2)%M2*p2[N-l]%M2});
        else if(cmd=="R--") chk.push_back({(H1[--r]-H1[l]+M1)%M1*p1[N-l]%M1,(H2[r]-H2[l]+M2)%M2*p2[N-l]%M2});
        else if(cmd=="L++") chk.push_back({(H1[r]-H1[++l]+M1)%M1*p1[N-l]%M1,(H2[r]-H2[l]+M2)%M2*p2[N-l]%M2});
        else if(cmd=="L--") chk.push_back({(H1[r]-H1[--l]+M1)%M1*p1[N-l]%M1,(H2[r]-H2[l]+M2)%M2*p2[N-l]%M2});
    }

    sort(chk.begin(),chk.end());
    cout<<unique(chk.begin(),chk.end())-chk.begin();
}
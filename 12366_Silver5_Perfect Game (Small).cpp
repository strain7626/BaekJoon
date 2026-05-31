#include <bits/stdc++.h>

using namespace std;

int N,L[20],P[20],idx[20];

void solve(int t) {
    cin>>N;
    for(int i=0;i<N;i++) cin>>L[i],idx[i]=i;
    for(int i=0;i<N;i++) cin>>P[i];

    sort(idx,idx+N,[](int i,int j){return L[i]*P[j]==L[j]*P[i]?i<j:L[i]*P[j]<L[j]*P[i];});

    cout<<"Case #"<<t<<": ";
    for(int i=0;i<N;i++) cout<<idx[i]<<' ';
    cout<<'\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t;cin>>t;for(int i=1;i<=t;i++) solve(i);
}
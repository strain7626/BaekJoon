#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int N,M,K;cin>>N>>M>>K;
    if(N==M) {cout<<-1;return 0;}
    for(int i=1;i<K;i++) cout<<i<<' '; 
    for(int i=N;i>M;i--) cout<<i<<' '; 
    for(int i=K;i<=M;i++) cout<<i<<' '; 
}
#include <bits/stdc++.h>

using namespace std;

int N,M,DP[1001],val[1001],L[1001],R[1001];

int main() {
    cin.tie(0)->sync_with_stdio(0); 
    
    cin>>N>>M;
    for(int j=1;j<=M;j++) cin>>DP[j],DP[j]+=DP[j-1];

    while(--N) {
        for(int i=1;i<=M;i++) cin>>val[i];
        L[1]=DP[1]+val[1];
        R[M]=DP[M]+val[M];
        for(int i=2;i<=M;i++) L[i]=max(L[i-1],DP[i])+val[i];
        for(int i=M-1;i>0;i--) R[i]=max(R[i+1],DP[i])+val[i];
        for(int i=1;i<=M;i++) DP[i]=max(L[i],R[i]);
    }
    cout << DP[M];
}
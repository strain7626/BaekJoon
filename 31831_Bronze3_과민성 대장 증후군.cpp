#include <bits/stdc++.h>

using namespace std;

int N,M,A[100001],ans;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    cin>>N>>M;
    for(int i=1;i<=N;i++) {
        cin>>A[i];
        ans+=((A[i]+=max(A[i-1],0))>=M);
    }
    cout<<ans;
}
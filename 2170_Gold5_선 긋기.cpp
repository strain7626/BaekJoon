#include <bits/stdc++.h>

using namespace std;

int N;
pair<int,int> A[1000000];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    cin>>N;
    for(int i=0;i<N;i++) cin>>A[i].first>>A[i].second;

    sort(A,A+N);
    
    int M=-2e9;
    long long ans=0;
    for(int i=0;i<N;i++) {
        ans+=max(0,A[i].second-max(A[i].first,M));
        M=max(M,A[i].second);
    }
    cout<<ans;
}
#include <bits/stdc++.h>

using namespace std;

long long N,K,DP[500001],m,sum;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin>>N>>K;
    for(int i=1;i<=N;i++) {
        cin>>DP[i];sum+=DP[i];
        DP[i]+=min(m,DP[i-1]);
        if(i>K) m=min(m,DP[i-K]);
    }
    cout<<sum-*min_element(DP,DP+N+1);
}
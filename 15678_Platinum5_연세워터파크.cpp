#include <bits/stdc++.h>

using namespace std;
using ll=long long;

ll N,D,DP[100001];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin>>N>>D;
    deque<int>DQ;DQ.push_back(0);
    for (int i=1;i<=N;i++) {
        ll x;cin>>x;
        if(DQ.front()<i-D)DQ.pop_front();
        DP[i]=x+(DP[DQ.front()]>0?DP[DQ.front()]:0);
        while(!DQ.empty()&&DP[i]>=DP[DQ.back()])DQ.pop_back();
        DQ.push_back(i);
    }
    cout<<*max_element(DP+1,DP+N+1);
}   
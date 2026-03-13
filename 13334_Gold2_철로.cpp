#include <bits/stdc++.h>

using namespace std;
using pii=pair<int,int>;

int N,d;
pii A[100000];
priority_queue<pii,vector<pii>,greater<>> PQ;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    cin>>N;
    for(int i=0;i<N;i++) {
        int h,o;cin>>h>>o;
        A[i]=(h>o?pair{o,h}:pair{h,o});
    }
    cin>>d;

    sort(A,A+N,[](pii &a,pii &b){return a.second<b.second;});

    int ans=0;
    for(int i=0;i<N;i++) {
        PQ.push(A[i]);
        while(!PQ.empty()&&PQ.top().first<A[i].second-d) PQ.pop();
        ans=max(ans,int(PQ.size()));
    }
    cout<<ans;
}
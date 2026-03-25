#include <bits/stdc++.h>

using namespace std;
using ll=long long;

int N;
ll DP[100001][20];
vector<int> adj[100001],E[100001];

void init(int now,int pre) {
	for(auto nxt:adj[now]) if(nxt != pre) E[now].push_back(nxt),init(nxt,now);
}

ll solve(int now,int val){
    ll& res=DP[now][val];
    if(res) return res;

    for(int nxt:E[now]) {
        ll tmp=1e6;
        for(int i=1;i<20;i++) if(i!=val) tmp=min(tmp,solve(nxt,i));
        res+=tmp;
    }

    return res+=val;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);

	cin >> N;
	for(int i=1;i<N;i++){
		int a,b;cin>>a>>b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	init(1,1);

	ll ans=1e16;
	for(int i=1;i<20;i++) ans=min(ans,solve(1,i));
	cout<<ans;
}
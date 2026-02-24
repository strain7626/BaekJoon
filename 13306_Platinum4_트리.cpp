#include <bits/stdc++.h>

using namespace std;

int N,Q,par[200001],uni[200001];
vector<tuple<int,int,int>> query;
vector<string> ans;

int uni_find(int n) {return uni[n]=(n==uni[n]?n:uni_find(uni[n]));}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    cin>>N>>Q;
    for (int i=1;i<=N;i++) uni[i]=i;
    for (int i=2;i<=N;i++) cin>>par[i]; par[1]=1;

    int T=N-1+Q;
    while (T--) {
        int x,a,b;cin>>x>>a;
        if (x) cin>>b;
        query.push_back({x,a,b});
    }
    
    reverse(query.begin(),query.end());
    for (auto [x,a,b]:query) {
        if (x) ans.push_back(uni_find(a)==uni_find(b)?"YES\n":"NO\n");       
        else uni[a]=par[a];
    } 
    
    reverse(ans.begin(),ans.end());
    for (auto i:ans) cout<<i;
}
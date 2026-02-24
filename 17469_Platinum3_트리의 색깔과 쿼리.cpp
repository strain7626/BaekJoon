#include <bits/stdc++.h>

using namespace std;

int N,Q,uni[100001],p[100001];
set<int> c[100001];
vector<pair<int,int>> query;
vector<int> ans;

int uni_find(int n) {return uni[n]=(n==uni[n]?n:uni_find(uni[n]));}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    cin>>N>>Q;
    for(int i=2;i<=N;i++) cin>>p[i];
    for(int i=1;i<=N;i++) {int x;cin>>x;c[i].insert(x);uni[i]=i;}

    for(int i=0;i<N+Q-1;i++) {
        int x,a;cin>>x>>a;
        query.push_back({x,a});
    }
    reverse(query.begin(),query.end());

    for(auto [x,a]:query) {
        int b=uni_find(p[a]);a=uni_find(a);
        if(x==1) {
            if(c[a].size()>c[b].size()) swap(a,b);
            for(int i:c[a]) c[b].insert(i);
            uni[a]=uni[b];
        } else ans.push_back(c[uni_find(a)].size());
    }
    reverse(ans.begin(),ans.end());

    for(int i:ans) cout<<i<<'\n';
}
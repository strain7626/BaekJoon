#include <bits/stdc++.h>

using namespace std;

int N,Q,idx[500001];
set<int> s[500001];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    cin>>N>>Q;
    for (int i=1;i<=N;i++) {
        idx[i]=i;
        int n,x;cin>>n;
        while (n--) cin>>x,s[i].insert(x);
    }
    while (Q--) {
        int cmd;cin>>cmd;
        if (cmd==1) {
            int a,b;cin>>a>>b;
            if (s[idx[a]].size()<s[idx[b]].size()) swap(idx[a],idx[b]);
            for (int i:s[idx[b]]) s[idx[a]].insert(i);
            s[idx[b]].clear();
        } else {
            int a;cin>>a;
            cout << s[idx[a]].size() << '\n';
        }
    }
}
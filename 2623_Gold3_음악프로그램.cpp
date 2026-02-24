#include <bits/stdc++.h>

using namespace std;

int N,M,I[1001];
vector<int> E[1001];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    cin >> N >> M;
    for (int i=0;i<M;i++) {
        int x; cin >> x; vector<int> A(x);
        for (int &a:A) cin >> a;
        for (int i=0;i<x-1;i++) E[A[i]].push_back(A[i+1]),I[A[i+1]]++;
    }

    queue<int> Q;
    for (int i=1;i<=N;i++) if (!I[i]) Q.push(i);

    vector<int> ans;
    while (!Q.empty()) {
        int now = Q.front(); Q.pop();
        ans.push_back(now);

        for (int e:E[now]) if (!--I[e]) Q.push(e);
    }

    if (ans.size() == N) for (int i:ans) cout << i << '\n';
    else cout << 0;
}
#include <bits/stdc++.h>

using namespace std;

int N, M;
set<int> X;
vector<bool> ans;
vector<vector<int>> party;


int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N >> M;
    int T; cin >> T; while (T--) {
        int t; cin >> t;
        X.insert(t);
    }

    ans.resize(M,1);
    party.resize(M);
    for (auto& P : party) {
        int T; cin >> T; P.resize(T);
        for (int& p : P) cin >> p;
    }

    for (int i = 0; i < M; i++) for (int j = 0; j < M; j++) {
        if (!ans[j]) continue;
        for (int& p : party[j]) if (X.count(p)) ans[j] = 0;
        
        if (ans[j]) continue;
        for (int& p : party[j]) X.insert(p);
    }
    
    cout << count(ans.begin(), ans.end(),1);
}
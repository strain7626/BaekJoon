#include <bits/stdc++.h>

using namespace std;

int N;
map<char,vector<char>> M;
set<string> ans;

void BFS(char a) {
    queue<char> Q;
    for (char b : M[a]) Q.push(b);

    while(!Q.empty()) {
        char b = Q.front(); Q.pop();
        string S = ""s + a + " => " + b;

        if (ans.count(S) || a==b) continue;

        ans.insert(S);
        for (char c : M[b]) Q.push(c);
    }
}

int main() {
    cin.tie(0);ios_base::sync_with_stdio(0);

    cin >> N;
    for (int i = 0; i < N; i++) {
        char a, b; cin >> a >>b>>b>> b;
        M[a].push_back(b);
    }
    
    for (auto& [a, b] : M) BFS(a);

    cout << ans.size() << '\n';
    for (auto& S : ans) cout << S << '\n';
}
#include <bits/stdc++.h>

using namespace std;

string S;
int K;
vector<int> T[200];

int make(int now) {
    if (S[now]!='(') return now+1;

    int nxt=now+1;
    while (S[nxt]!=')') {
        T[now].push_back(nxt);
        nxt=make(nxt);
    }
    return nxt+1;
}

set<string> DFS(int now) {
    if (S[now]!='(') return {{S[now]}};
    // cout << now<<"진입->";

    int t=T[now].size();
    vector<vector<string>> V(t+1);
    V[0].push_back("");

    for (int i=0;i<t;i++) {
        for (auto ns:DFS(T[now][i])) {
            for (auto ps:V[i]) V[i+1].push_back(ps+ns);
        }
        // for (auto s:V[i]) cout << s << ' ';
        cout << '\n';
    }

    set<string> res;
    for (auto s:V[t]) {
        res.insert(s);
        reverse(s.begin(),s.end());
        res.insert(s);
    }
    return res;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> S >> K;
    make(0);

    int cnt=1;
    for (auto s:DFS(0)) {
        if (K==cnt++) {cout << s; return 0;}
    }
    cout << "NO";
}
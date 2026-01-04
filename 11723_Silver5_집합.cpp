#include <bits/stdc++.h>

using namespace std;

set<int> S;

int main() {
    cin.tie(0);ios_base::sync_with_stdio(0);
    int M; cin >> M;
    while (M--) {
        string s; cin >> s;
        if (s == "add") {
            int x; cin >> x; S.insert(x);
        } else if (s == "remove") {
            int x; cin >> x; S.erase(x);
        } else if (s == "check") {
            int x; cin >> x; cout << S.count(x) << '\n';
        } else if (s == "toggle") {
            int x; cin >> x; 
            if (S.count(x)) S.erase(x);
            else S.insert(x);
        } else if (s == "all") {
            for (int i = 1; i <= 20; i++) S.insert(i);
        } else if (s == "empty") {
            S.clear();
        }
    }
}
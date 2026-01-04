#include <bits/stdc++.h>
using namespace std;

int N, M;
map<string, string> S;

int main() {
    cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);

    cin >> N >> M;
    while (N--) {
        string s1, s2; cin >> s1 >> s2;
        S[s1] = s2;
    }
    while (M--) {
        string s1; cin >> s1;
        cout << S[s1] << '\n';
    }
}
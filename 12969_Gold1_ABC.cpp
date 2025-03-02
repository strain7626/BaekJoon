#include <bits/stdc++.h>
using namespace std;

int N, K;
bool DP[31][31][31][450];

string Solve(string pre, int k) {
    int cnt[3] = {0,0,0};
    for (char c : pre) cnt[c-'A']++;

    if (pre.size() == N) {
        if (k == K) return pre;
        else return "-1";
    }
    if (DP[cnt[0]][cnt[1]][cnt[2]][k]) return "-1";

    DP[cnt[0]][cnt[1]][cnt[2]][k] = true;

    string r;
    r = Solve(pre+'A', k);
    if (r != "-1") return r;
    r = Solve(pre+'B', k+cnt[0]);
    if (r != "-1") return r;
    r = Solve(pre+'C', k+cnt[0]+cnt[1]);
    if (r != "-1") return r;

    return "-1";
}

int main() {
    cin >> N >> K;
    cout << Solve("",0);
}
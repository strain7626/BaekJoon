#include <bits/stdc++.h>
using namespace std;

int N, C;
vector<int>     A,      B,
                Asum,   Bsum;
map<int,int>    Acnt,   Bcnt;
int ans;

void DFS(int idx, int val, vector<int> &T, vector<int> &Tsum, map<int,int> &Tcnt) {
    if (idx == T.size()) return;

    // 현재 미포함
    if (idx) DFS(idx+1, val, T, Tsum, Tcnt);

    // 현재 포함
    val += T[idx];
    if (val <= C) {
        if (Tcnt[val] == 0) Tsum.push_back(val);
        Tcnt[val]++;
        DFS(idx+1, val, T, Tsum, Tcnt);
    }
}

int main() {
    cin >> N >> C;
    A.push_back(0);
    B.push_back(0);
    for (int i = 0; i < N/2; i++) {int t; cin >> t; A.push_back(t);}
    for (int i = N/2; i < N; i++) {int t; cin >> t; B.push_back(t);}
    
    DFS(0, 0, A, Asum, Acnt);
    DFS(0, 0, B, Bsum, Bcnt); 
    
    sort(Asum.begin(), Asum.end());
    sort(Bsum.begin(), Bsum.end());

    for (int i = 1; i < Asum.size(); i++) Acnt[Asum[i]] += Acnt[Asum[i-1]];

    int a = 0, b = Bsum.size();

    ans = 0;
    while(b--) {
        while (a < Asum.size() && Asum[a]+Bsum[b] <= C) a++;
        ans += Acnt[Asum[--a]] * Bcnt[Bsum[b]];
    }

    cout << ans;
}
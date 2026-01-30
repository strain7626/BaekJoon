#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<int> A, ans;

void DFS(int cnt, int idx) {
    if (!cnt) {
        for (int& i : ans) cout << i << ' '; cout << '\n';
        return;
    }

    for (int i = idx; i < A.size(); i++) {
        ans.push_back(A[i]);
        DFS(cnt-1, i);
        ans.pop_back();
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        int x; cin >> x;
        bool flag = 0;
        for (int& y : A) if (x==y) flag = 1;
        if (!flag) A.push_back(x);
    } sort(A.begin(),A.end());
    DFS(M, 0);
}
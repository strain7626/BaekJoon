#include <bits/stdc++.h>

using namespace std;

int n, k;
vector<int> A;

int solution() {
    queue<int> Q;
    vector<int> parent(n);

    Q.push(-1); Q.push(0); parent[0] = -1;
    for (int i = 0; i < n; i++) if (A[i] == k) k = i;
    for (int i = 1; i < n; i++) {
        Q.push(i);

        if (A[i] != A[i-1]+1) Q.pop();
        parent[i] = Q.front();
    }

    if (parent[k] == -1 || parent[parent[k]] == -1) return 0;

    int ans = 0;
    for (int i = 1; i < n; i++) {
        if (parent[i] == -1) continue;
        if (parent[k] == parent[i]) continue;
        else if (parent[parent[k]] == parent[parent[i]]) ans++;
    }

    return ans;
}

int main() {
    cin.tie(0);ios_base::sync_with_stdio(0);

    while (1) {
        cin >> n >> k; A.resize(n);
        for (int& a : A) cin >> a;
        
        if (n==0 && k==0) exit(0);
        cout << solution() << '\n';
    }
}
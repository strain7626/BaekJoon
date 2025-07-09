#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, t[500], g[501], m, inDegree[501];

int main() {
    int T; cin >> T;
    while (T--) {
        vector<int> E[501];
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> t[i];
            g[t[i]] = i+1;
            inDegree[t[i]] = i;
        }
        for (int i = 0; i < n-1; i++) for (int j = i+1; j < n; j++) {
            E[t[i]].push_back(t[j]);
        }
        cin >> m;
        for (int i = 0; i < m; i++) {
            int a, b; cin >> a >> b;
            if (g[a] > g[b]) swap(a,b);
            inDegree[a]++;inDegree[b]--;
            E[b].push_back(a);
            for (int &i : E[a]) if (i == b) {i = 0; break;}
        }

        queue<int> Q;
        for (int i = 1; i <= n; i++) if (!inDegree[i]) Q.push(i);
        
        vector<int> ans;
        bool flag = 0;
        while (!Q.empty()) {
            if (Q.size() != 1) {cout << "?\n";flag=1;break;}
            ans.push_back(Q.front());
            for (int e : E[Q.front()]) if (e) {
                inDegree[e]--;
                if (inDegree[e] == 0) Q.push(e);
            }
            if (flag) break;
            Q.pop();
        }

        if (flag) continue;
        if (ans.size() != n) {cout << "IMPOSSIBLE\n";continue;}
        for (int i : ans) cout << i << ' ';
        cout << '\n';
    }
}
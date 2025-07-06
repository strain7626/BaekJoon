#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n, t[501], g[501], m;
vector<int> E[501];
int inDegree[501];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {cin >> t[i]; g[t[i]] = i;}
    for (int i = 1; i <= n; i++) {
        inDegree[t[i]] = i-1;
        for (int j = i+1; j <= n; j++) E[t[i]].push_back(t[j]);
    }
    cin >> m;
    while (m--) {
        int t1, t2; cin >> t1 >> t2;
        if (g[t1] > g[t2]) swap(t1, t2);

        E[t1].erase(find(E[t1].begin(),E[t1].end(),t2));
        E[t2].push_back(t1);

        inDegree[t1]++;
        inDegree[t2]--;
    }

    queue<int> Q;
    for (int i = 0; i < n; i++) {
        if (inDegree[i] == 0) Q.push(i);
    }

    while (!Q.empty()) {
        cout << Q.front();
        for (int i : E[Q.front()]) {
            inDegree[i]--;
            if (inDegree[i] == 0) Q.push(i);
            if (inDegree[i] == -1) cout << "IMPOSSIBLE";
        }
        Q.pop();
        if (Q.size() != 1) cout << "?";
    }

    


}
#include <bits/stdc++.h>
using namespace std;

int cnt;
int N, M;
int main() {
    int T; cin >> T;
    while (T--) {
        cnt = 0;
        cin >> N >> M;
        queue<pair<int, int>> q;
        priority_queue<int> pq;
        
        for (int i = 0; i < N; i++) {
            int a; cin >> a;
            q.push({i,a});
            pq.push(a);
        }

        while (!q.empty()) {
            int idx = q.front().first, val = q.front().second;
            q.pop();

            if (pq.top() == val) {
                pq.pop();
                cnt++;

                if (idx == M) {
                    cout << cnt << endl;
                    break;
                }
            }
            else q.push({idx,val});
        }
    }
}
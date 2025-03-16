#include <bits/stdc++.h>
using namespace std;

int n;
priority_queue<pair<int,int>> PQ; // p가 큰 값대로 정렬
bool visited[10001]; // i 번째 날 강연을 할 예정이면 true
int ans;

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        int p, d; cin >> p >> d;
        PQ.push({p,d});
    }

    ans = 0;
    while (!PQ.empty()) {
        int p = PQ.top().first, d = PQ.top().second;
        PQ.pop();

        // 최대한 뒷 날짜에 예정하기
        for (int i = d; i >= 1; i--) if (!visited[i]) {
            visited[i] = 1;
            ans += p;
            break;
        }
    }

    cout << ans;
}
#include <iostream>
#include <queue>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    int T; cin >> T;
    while (T--) {
        int K; cin >> K;
        priority_queue<long long, vector<long long>, greater<>> PQ;

        for (int i = 0; i < K; i++) { int x; cin >> x; PQ.push(x); }

        long long ans = 0;
        while (PQ.size() >= 2) {
            long long sum = 0;
            sum += PQ.top(); PQ.pop();
            sum += PQ.top(); PQ.pop();
            ans += sum;
            PQ.push(sum);
        }

        cout << ans << '\n';
    }
}
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int N, K, E[100000];
ll DP[100000];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N >> K;
    for (int i = 0; i < N; i++) cin >> E[i];
    
    deque<ll> DQ;
    DQ.push_back(0); DP[0] = E[0];

    ll sum = E[0];
    for (int i = 1; i < N; i++) {
        sum += E[i];
        if (DQ.front() < i-K-1) DQ.pop_front();

        DP[i] = E[i] + (i>K ? DP[DQ.front()] : 0);
        while (!DQ.empty() && DP[i] <= DP[DQ.back()]) DQ.pop_back();
        DQ.push_back(i);
    }

    if (N == K) cout << sum;
    else cout << sum - *min_element(DP+N-K-1,DP+N);
}
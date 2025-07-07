#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int N, K, C[300000];
pair<int,int> MV[300000];

struct cmp {
    bool operator() (pair<int,int> A, pair<int,int> B){
        return A.second < B.second;
    }
};

int main() {
    cin >> N >> K;
    for (int i = 0; i < N; i++) cin >> MV[i].first >> MV[i].second;
    for (int i = 0; i < K; i++) cin >> C[i];

    sort(MV, MV+N);
    sort(C, C+K);

    int t = 0;
    long long ans = 0;
    priority_queue<pair<int,int>, vector<pair<int,int>>, cmp> PQ;
    for (int i = 0; i < K; i++) {
        while (t < N && MV[t].first <= C[i]) PQ.push(MV[t++]);
        if (PQ.empty()) continue;
        ans += PQ.top().second;
        PQ.pop();
    }
    cout << ans;
}
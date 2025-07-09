#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M, inDegree[32001];
vector<int> E[32001];

int main() {
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int A, B; cin >> A >> B;
        E[A].push_back(B);
        inDegree[B]++;
    }

    priority_queue<int, vector<int>, greater<>> PQ;
    for (int i = 1; i <= N; i++) if (!inDegree[i]) PQ.push(i);

    while (!PQ.empty()) {
        int t = PQ.top(); PQ.pop();
        cout << t << ' ';
        for (int i : E[t]) if (!--inDegree[i]) PQ.push(i);
    }
}
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;
int I[32001];
vector<int> E[32001];

int main() {
    cin >> N >> M;
    while (M--) {
        int A, B; cin >> A >> B;
        E[A].push_back(B);
        I[B]++;
    }

    queue<int> Q;
    for (int i = 1; i <= N; i++) if (!I[i]) Q.push(i); 

    while (!Q.empty()) {
        cout << Q.front() << ' ';

        for (int i : E[Q.front()]) if (!--I[i]) Q.push(i);

        Q.pop();
    }
}
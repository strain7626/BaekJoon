#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int N; cin >> N;
    vector<int> A(N), DP(N, -1); DP[0] = 0;
    for (int &i : A) cin >> i;

    queue<int> Q;
    Q.push(0);
    
    while (!Q.empty()) {
        int now = Q.front();
        Q.pop();

        for (int i = 1; i <= A[now]; i++) 
            if (now+i >= N) break;
            else if (DP[now+i] == -1 || DP[now+i] > DP[now]+1) {
                DP[now+i] = DP[now]+1;
                Q.push(now+i);
            }
    }

    cout << DP[N-1];
}
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int N, A[501], DP[501];
vector<int> pre[501];

void Input() {
    cin >> N;
    for (int i=1;i<=N;i++) {
        cin >> A[i];
        int t = 0;
        while (t != -1) {
            cin >> t; pre[i].push_back(t);
        }

        if (pre[i].empty()) DP[i] = A[i];
    }
}

int DFS(int a) {
    if (DP[a] == 0) {
        int M = 0;
        for (int i : pre[a]) M = max(M,DFS(i));
        DP[a] = M+A[a];
    }
    return DP[a];
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    Input();
    for (int i = 1; i <= N; i++) cout << DFS(i) << endl;
}
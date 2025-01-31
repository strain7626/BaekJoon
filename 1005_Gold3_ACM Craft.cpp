#include <iostream>
#include <vector>
#include <algorithm>
#define endl "\n"
using namespace std;

int N, K, W, T[1001];
vector<int> pre[1001];
int DP[1001];
int result;

void Input() {
    cin >> N >> K;
    for (int i=1;i<=N;i++) {
        cin >> T[i];
        pre[i].clear();
        DP[i] = -1;
    }
    for (int i=1;i<=K;i++) {
        int X, Y; cin >> X >> Y;
        pre[Y].push_back(X);
    }
    cin >> W;
}

int DFS(int _W) {
    if (DP[_W] != -1) return DP[_W];

    DP[_W] = 0;
    for (int i : pre[_W]) 
        DP[_W] = max(DP[_W], DFS(i));

    return DP[_W] += T[_W];
}
void Solve() {
    result = DFS(W);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int _T; cin >> _T;
    while (_T--) {
        Input();
        Solve();
        cout << result << endl;
    }
}
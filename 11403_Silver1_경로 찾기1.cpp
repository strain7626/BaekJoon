#include <bits/stdc++.h>

using namespace std;

int N;
bool G[100][100];

int main() {
    cin.tie(0);ios_base::sync_with_stdio(0);
    
    cin >> N;
    for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) cin >> G[i][j];
    for (int k = 0; k < N; k++) for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) if (G[i][k]&&G[k][j]) G[i][j]=1;
    for (int i = 0; i < N; i++) { for (int j = 0; j < N; j++) cout << G[i][j] << ' '; cout << '\n'; }
}
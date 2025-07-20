#include <iostream>
using namespace std;

int N, A[11], O[4], M = -1e9, m = 1e9;

void DFS(int now, int cnt) {
    if (cnt == N) { M = max(M, now); m = min(m, now); }

    if (O[0]) { O[0]--; DFS(now+A[cnt], cnt+1); O[0]++; }
    if (O[1]) { O[1]--; DFS(now-A[cnt], cnt+1); O[1]++; }
    if (O[2]) { O[2]--; DFS(now*A[cnt], cnt+1); O[2]++; }
    if (O[3]) { O[3]--; DFS(now/A[cnt], cnt+1); O[3]++; }
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) cin >> A[i];
    for (int i = 0; i < 4; i++) cin >> O[i];

    DFS(A[0], 1);

    cout << M << '\n' << m;
}
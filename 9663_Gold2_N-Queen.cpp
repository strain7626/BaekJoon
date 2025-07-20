#include <iostream>
using namespace std;

int N;
bool cx[15], c1[29], c2[29];

int DFS(int y) {
    if (y == N) return 1;
    
    int ans = 0;
    for (int x = 0; x < N; x++) {
        if (cx[x] || c1[x+y] || c2[x+14-y]) continue;
        cx[x] = c1[x+y] = c2[x+14-y] = 1;
        ans += DFS(y+1);
        cx[x] = c1[x+y] = c2[x+14-y] = 0;
    }

    return ans;
}

int main() {
    cin >> N;
    cout << DFS(0);
}
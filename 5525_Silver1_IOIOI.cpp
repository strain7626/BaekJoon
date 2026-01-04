#include <bits/stdc++.h>

using namespace std;

int N, M;
string S;

int main() {
    cin.tie(0);ios_base::sync_with_stdio(0);

    cin >> N >> M; N = 2*N+1;

    int ans = 0, cnt = 0;
    for (int i = 0; i < M; i++) {
        char c; cin >> c;
        
        if (cnt%2 == 0 && c == 'I') cnt++;
        else if (cnt%2 && c == 'O') cnt++;
        else cnt = c=='I';

        if (cnt == N) {
            cnt -= 2;
            ans++;
        }
    }

    cout << ans;
}
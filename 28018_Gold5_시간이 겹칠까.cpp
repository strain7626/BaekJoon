#include <iostream>
using namespace std;

int N, ans[1000001], Q;

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++) {
        int S, E; cin >> S >> E;
        ans[S]++; ans[E+1]--;
    }
    for (int i = 1; i <= 1000000; i++) ans[i] += ans[i-1];

    cin >> Q;
    for (int i = 0; i < Q; i++) {
        int x; cin >> x;
        cout << ans[x] << '\n';
    }
}
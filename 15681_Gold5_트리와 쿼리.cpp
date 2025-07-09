#include <iostream>
#include <vector>
using namespace std;

int N, R, Q;
vector<int> E[100001];
int ans[100001];

int DFS(int parent, int now) {
    for (int i : E[now]) if (i != parent) 
        ans[now] += DFS(now, i);
    return ++ans[now];
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    cin >> N >> R >> Q;
    for (int i = 0; i < N-1; i++) {
        int U, V; cin >> U >> V;
        E[U].push_back(V); E[V].push_back(U);
    }

    for (int i : E[R]) ans[R] += DFS(R, i);
    ans[R]++;

    for (int i = 0; i < Q; i++) {
        int q; cin >> q;
        cout << ans[q] << '\n';
    }
}
#include <bits/stdc++.h>
using namespace std;

int N, M;
int uni[201];

int uni_find(int ori) {
    if (uni[ori] == ori) return ori;
    else return uni[ori] = uni_find(uni[ori]);
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    cin >> N >> M;
    for (int i = 1; i <= N; i++) uni[i] = i;
    for (int i = 1; i <= N; i++) for (int j = 1; j <= N; j++) {
        bool flag; cin >> flag;
        if (flag) {
            if (j > i) uni[uni_find(j)] = uni_find(i);
            else uni[uni_find(i)] = uni_find(j);
        }
    }

    int dest; cin >> dest;
    int cmp = uni_find(dest);
    
    for (int i = 0; i < M-1; i++) {
        cin >> dest;
        if (cmp != uni_find(dest)) {
            cout << "NO";
            exit(0);
        }
    }

    cout << "YES";
}
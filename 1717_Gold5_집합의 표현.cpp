#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

int n, m;
int uni[1000001];

int uni_find(int ori) {
    if (uni[ori] == ori) return ori;
    return uni[ori] = uni_find(uni[ori]);
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    cin >> n >> m;
    for (int i = 0; i <= n; i++) uni[i] = i;
    for (int i = 0; i < m; i++) {
        int a, b, c; cin >> a >> b >> c;
        b = uni_find(b);
        c = uni_find(c);
        if (a == 0) {
            if (b > c) swap(b, c);
            uni[c] = b;
        } else {
            cout << (b == c ? "YES" : "NO") << endl;
        }
    }
}
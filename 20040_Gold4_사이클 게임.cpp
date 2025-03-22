#include <bits/stdc++.h>
using namespace std;

int n, m;
int uni[500000];

int uni_find(int num) {
    return (uni[num] == num ? num : uni[num] = uni_find(uni[num]));
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++) uni[i] = i;

    int ans = 0;
    for (int i = 1; i <= m; i++) {
        int a, b; cin >> a >> b;

        if (ans) continue;
        a = uni_find(a); b = uni_find(b);
        if (a==b && ans==0) ans = i;
        uni[a] = b;
    }
    cout << ans;
}
#include <bits/stdc++.h>

using namespace std;

using vi = vector<int>;
using vvi = vector<vector<int>>;

int num = 1;
vvi base = {{-1,1},{1,1}};

vvi rotate(vvi &X, int cnt) {
    if (!cnt) return X;

    int size = X.size();
    vvi res(size, vi(size));

    for (int i = 0; i < size; i++) for (int j = 0; j < size; j++)
        res[i][j] = X[size-j-1][i];

    return rotate(res, cnt-1);
}

vvi nxt_base() {
    int size = base.size();
    vvi res(size*2, vi(size*2));
    
    int d = num;
    vvi tmp = rotate(base, 1);
    for (int i = 0; i < size; i++) for (int j = 0; j < size; j++)
        res[size+i][j] = d+tmp[i][j];
    d+=num;
    tmp = rotate(tmp, 2);
    for (int i = 0; i < size; i++) for (int j = 0; j < size; j++)
        res[i][size+j] = d+tmp[i][j];
    d+=num;
    for (int i = 0; i < size; i++) for (int j = 0; j < size; j++)
        res[size+i][size+j] = d+base[i][j];
    d+=num;
    for (int i = 0; i < size; i++) for (int j = 0; j < size; j++)
        res[size/2+i][size/2+j] = d+base[i][j];

    num = d;
    return res;
}

vvi make_tile(int K, int x, int y) {
    int R = (x < 1<<K-1 ? (y < 1<<K-1 ? 0 : 3) : (y < 1<<K-1 ? 1 : 2));

    if (K==1) return rotate(base, R);
    
    vvi prev = make_tile(K-1, x%(1<<K-1), y%(1<<K-1));
    
    base = nxt_base();
    vvi res = rotate(base, R);

    int dx = (R==0||R==3 ? 0 : 1<<K-1);
    int dy = (R==0||R==1 ? 0 : 1<<K-1);

    for (int i = 0; i < 1<<K-1; i++) for (int j = 0; j < 1<<K-1; j++)
        res[dy+i][dx+j] = prev[i][j];

    return res;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int K, x, y;
    cin >> K >> x >> y;

    x = x-1;
    y = (1<<K)-y;

    vvi ans = make_tile(K, x, y);
    for (auto &i : ans) { for (int &j : i) cout << j << ' '; cout << '\n'; }
}
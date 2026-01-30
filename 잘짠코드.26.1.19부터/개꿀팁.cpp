#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(0)->sync_with_stdio(0);

    int now = 0;
    for (int nxt : {now-1,now+1,now*2}) cout << nxt;
    pair<int,int> A[] = {{1,2},{3,4}};
    for (auto [a, b]: A) cout << a << b;
    
    int A;
    int N = A = 10;
    for (int i = 0; i < N; cout << '\n', ++i) cout << i;

    int x,y,d;
    int nx = x + "0121"[d] - '1';
    int ny = y + "1012"[d] - '1';
    
    for (int i = 0; i < N; i++, puts("")) printf("%d", i);
}
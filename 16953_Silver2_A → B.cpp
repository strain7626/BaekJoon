#include <bits/stdc++.h>

using ll = long long;
using namespace std;

ll A, B;

int DFS(int cnt, ll num) {
    if (num > B) return -1;
    if (num == B) return cnt;
    
    int r1 = DFS(cnt+1, num*2), r2 = DFS(cnt+1, num*10+1);
    if (r1==-1) return r2;
    if (r2==-1) return r1;
    return min(r1,r2);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> A >> B;
    cout << DFS(1, A);
}
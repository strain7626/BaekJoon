#include <bits/stdc++.h>

using namespace std;

int N,D[20][20],DP[1<<20];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N;
    for (int i=0;i<N;i++) for (int j=0;j<N;j++) cin >> D[i][j];
    for (int i=1;i<(1<<N);i++) DP[i]=1e9;
    
    for (int i=0;i<(1<<N);i++) for (int j=0,b=1;j<N;b=(1<<++j)) {
        if (i&b) continue;
        DP[i|b]=min(DP[i|b],DP[i]+D[bitset<20>(i).count()][j]);
    }
    cout << DP[(1<<N)-1];
}
#include <bits/stdc++.h>

using namespace std;

int A[8];

bool CW(int a, int b, int c) {
    double tb = sin(atan(1))*b;
    return (tb*-tb-(c-tb)*(tb-a))<=0;    
}

int DFS(int vis, int p, int pp, int s, int ss) {
    if (vis==(1<<8)-1) return CW(A[pp],A[p],A[s])&&CW(A[p],A[s],A[ss]);

    int res=0;
    for (int i=0;i<8;i++) if (!(vis&(1<<i))&&CW(A[pp],A[p],A[i])) {
        res+=DFS(vis|(1<<i),i,p,s,ss);
    }
    return res;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    for (int &i:A) cin>>i;

    int ans=0;
    for (int i=0;i<8;i++) for (int j=0;j<8;j++) if (i-j) ans+=DFS((1<<i)|(1<<j),j,i,i,j);
    cout << ans;
}
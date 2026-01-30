#include <bits/stdc++.h>
#define MAX 5000

using namespace std;

int n,r,A[MAX+1],B[MAX+1];
vector<int> P;

int check(int N, int p) {
    int res=0;
    while (N>=p) res+=N/=p;
    return res;
}

int solve() {
    cin>>n>>r;r=min(r,n-r);
    for (int &p:P) A[p] = check(n,p)-check(r,p)-check(n-r,p);
    cin>>n>>r;r=min(r,n-r);
    for (int &p:P) B[p] = check(n,p)-check(r,p)-check(n-r,p);

    for (int &p:P) if (A[p]&&B[p]) return 0;
    return 1;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    bool isP[MAX+1];
    for (int i=2;i<=MAX;i++) isP[i]=1;
    for (int i=2;i<=MAX;i++) if (isP[i]) {
        for (int j=i+i;j<=MAX;j+=i) isP[j]=0;
        P.push_back(i);
    }

    int T;cin>>T;
    while (T--) cout << solve() << '\n';
}
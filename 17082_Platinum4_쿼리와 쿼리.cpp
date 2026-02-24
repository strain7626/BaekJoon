#include <bits/stdc++.h>
#define MAX 200000

using namespace std;

int N,M,Q,a[MAX+1],l[MAX],r[MAX],seg[4*MAX];
bool use[MAX+1];

int init(int n,int s,int e) {
    return seg[n]=(s==e?use[s]?a[s]:-1e9:max(init(n*2,s,(s+e)/2),init(n*2+1,(s+e)/2+1,e)));
}

int update(int n,int s,int e,int idx) {
    if (idx<s||e<idx) return seg[n];
    return seg[n]=(s==e?use[s]?a[s]:-1e9:max(update(n*2,s,(s+e)/2,idx),update(n*2+1,(s+e)/2+1,e,idx)));
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    cin >> N >> M >> Q;
    for (int i=1;i<=N;i++) cin>>a[i];
    for (int i=0;i<M;i++) cin>>l[i]; sort(l,l+M);
    for (int i=0;i<M;i++) cin>>r[i]; sort(r,r+M);

    for (int i=0;i<M;i++) if (l[i]>r[i]) {
        int i,j; while (Q--) {cin>>i>>j;cout<<int(1e9)<<'\n';}
        return 0;
    }
    
    for (int i=0,t=0;i<M;t=r[i++]+1) for (int j=max(t,l[i]);j<=r[i];j++) use[j]=1;
    init(1,1,N);

    while (Q--) {
        int i,j;cin>>i>>j;

        swap(a[i],a[j]);
        update(1,1,N,i);
        update(1,1,N,j);

        cout << seg[1] << '\n';
    }
}
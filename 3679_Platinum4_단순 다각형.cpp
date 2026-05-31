#include <bits/stdc++.h>
#define x first
#define y second

using namespace std;
using ll=long long;
using pos=pair<ll,ll>;

int N,idx[2000];
pos P[2000];

int ccw(pos A,pos B,pos C) {
    ll r=(B.x-A.x)*(C.y-A.y)-(B.y-A.y)*(C.x-A.x);
    return (r>0)-(r<0);
}

ll dist(pos A,pos B) {return abs(A.x-B.x)+abs(A.y-B.y);}

void solve() {
    cin>>N;
    for(int i=0;i<N;i++) cin>>P[i].x>>P[i].y,idx[i]=i;

    swap(idx[0],idx[min_element(P,P+N)-P]);
    sort(idx+1,idx+N,[&](int a,int b){
        pos O=P[idx[0]],A=P[a],B=P[b];
        return ccw(O,A,B)?ccw(O,A,B)>0:dist(O,A)<dist(O,B);
    });

    int e=N-1;
    while(e&&ccw(P[idx[e-1]],P[idx[e]],P[idx[0]])==0) e--;
    reverse(idx+e,idx+N);

    for(int i=0;i<N;i++) cout<<idx[i]<<' ';cout<<'\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T;cin>>T;while(T--)solve();    
}
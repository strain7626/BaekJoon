#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct pos{ll x,y;};

int N;
pos C[10000];

int CCW(pos A,pos B,pos C) {
    ll res = (B.x-A.x)*(C.y-B.y)-(B.y-A.y)*(C.x-B.x);
    return (res>0)-(res<0);
}

bool isInside(ll x,ll y) {
    bool res=0;
    for (int i=0,j=N-1;i<N;j=i++) {
        pos A=C[i],B=C[j];
        
        if (CCW(A,B,{x,y})==0&&min(A.x,B.x)<=x&&x<=max(A.x,B.x)&&min(A.y,B.y)<=y&&y<=max(A.y,B.y))
            return true;
    
        if ((A.y>y)!=(B.y>y)&&x<(double)(B.x-A.x)*(y-A.y)/(B.y-A.y)+A.x)
            res=!res;
    }
    return res;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    cin >> N;
    for (int i=0;i<N;i++) cin >> C[i].x >> C[i].y;

    for (int i=0;i<3;i++) {
        ll x,y;cin>>x>>y;
        cout << isInside(x,y) << '\n';
    }
}
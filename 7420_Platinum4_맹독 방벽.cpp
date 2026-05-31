#include <bits/stdc++.h>

using namespace std;
using ll=long long;

struct pos{
    ll x,y;
    bool operator<(const pos &o) {return (y==o.y?x<o.x:y<o.y);}
};

int N,L;
pos P[1000];

int ccw(pos A,pos B,pos C) {
    ll r=(B.x-A.x)*(C.y-A.y)-(B.y-A.y)*(C.x-A.x);
    return (r>0)-(r<0);
}

double dist(pos A,pos B) {
    return sqrt((A.x-B.x)*(A.x-B.x)+(A.y-B.y)*(A.y-B.y));
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    cin>>N>>L;
    for(int i=0;i<N;i++) cin>>P[i].x>>P[i].y;

    sort(P,P+N);
    pos O=P[0];
    sort(P+1,P+N,[&](pos A,pos B){return (ccw(O,A,B)?ccw(O,A,B)>0:dist(O,A)<dist(O,B));});


    int n=2;
    vector<pos> cvx={P[0],P[1]};
    for(int i=2;i<N;i++) {
        while(n>=2&&ccw(cvx[n-2],cvx[n-1],P[i])<=0) cvx.pop_back(),n--;
        cvx.push_back(P[i]),n++;
    }

    double sum=dist(cvx[0],cvx[n-1]);
    for(int i=0;i<n-1;i++) sum+=dist(cvx[i],cvx[i+1]);

    double pi=4*atan(1);
    cout<<round(sum+2*pi*L);
}
#include <bits/stdc++.h>
#define x first
#define y second

using namespace std;
using ll=long long;
using pos=pair<ll,ll>;

int N,M;

int ccw(pos A,pos B,pos C) {
    ll r=(B.x-A.x)*(C.y-A.y)-(B.y-A.y)*(C.x-A.x);
    return (r>0)-(r<0);
}

void cvx(int &sz,vector<pos> &cvX) {
    vector<pos> X(sz);
    for(auto &[x,y]:X) cin>>x>>y;

    swap(X[0],*min_element(X.begin(),X.end()));
    sort(X.begin()+1,X.end(),[&](pos &A,pos &B){return ccw(X[0],A,B)?ccw(X[0],A,B)>0:abs(A.x-X[0].x)+abs(A.y-X[0].y)<abs(B.x-X[0].x)+abs(B.y-X[0].y);});

    int n=0;
    for(auto i:X) {
        while(n>=2&&ccw(cvX[n-2],cvX[n-1],i)<=0) cvX.pop_back(),n--;
        cvX.push_back(i),n++;
    }
    sz=n;
}

bool isIntersect(pos A,pos B,pos C,pos D) {
    int ab=ccw(A,B,C)*ccw(A,B,D),cd=ccw(C,D,A)*ccw(C,D,B);

    if(!ab&&!cd) {
        if(A>B) swap(A,B);
        if(C>D) swap(C,D);
        return !(B<C||D<A);
    }

    return ab<=0&&cd<=0;
}

bool isInside(vector<pos> &cvX,pos p) {
    int n=cvX.size();
    if(n<3) return 0;

    for(int i=0;i<n;i++) if(ccw(cvX[i],cvX[(i+1)%n],p)<=0) return 0;

    return 1;
}

bool solve() {
    cin>>N>>M;
    vector<pos> A,B;
    cvx(N,A);
    cvx(M,B);

    for(int i=0;i<N;i++) for(int j=0;j<M;j++) if(isIntersect(A[i],A[(i+1)%N],B[j],B[(j+1)%M])) return 0;

    if (N>=3&&isInside(A,B[0])) return 0;
    if (M>=3&&isInside(B,A[0])) return 0;

    return 1;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t;cin>>t;while(t--) cout<<(solve()?"YES\n":"NO\n");    
}
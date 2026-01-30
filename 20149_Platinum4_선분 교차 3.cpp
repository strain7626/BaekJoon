#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

struct pos{
    ll x,y;
    bool operator>(pos X){
        if (x!=X.x) return x>X.x;
        return y>X.y;
    }
    bool operator<=(pos X){
        if (x!=X.x) return (x<X.x);
        return y<=X.y;
    }
    bool operator==(pos X){
        return (x==X.x)&&(y==X.y);
    }
};

int CCW(pos A,pos B,pos C) {
    ll res = (B.x-A.x)*(C.y-B.y)-(C.x-B.x)*(B.y-A.y);
	return (res>0)-(res<0);
}

bool isIntersect(pos A,pos B,pos C, pos D) {
    int AB = CCW(A,B,C)*CCW(A,B,D);
    int CD = CCW(C,D,A)*CCW(C,D,B);

    if (!AB&&!CD) {
        if (A>B) swap(A,B);
        if (C>D) swap(C,D);
        return (C<=B)&&(A<=D);
    }
    return (AB<=0)&&(CD<=0);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    pos A,B,C,D;
    cin>>A.x>>A.y>>B.x>>B.y>>C.x>>C.y>>D.x>>D.y;

    if (isIntersect(A,B,C,D)) cout << "1\n";
    else {
        cout << 0;
        return 0;
    }


    ld under = (A.x-B.x)*(C.y-D.y)-(A.y-B.y)*(C.x-D.x);
    if (under==0) {
        if (A>B) swap(A,B);
        if (C>D) swap(C,D);
        if (A==D) cout << A.x << ' ' << A.y;
        if (B==C) cout << B.x << ' ' << B.y;
        return 0;
    }

    ld x = ((A.x*B.y-A.y*B.x)*(C.x-D.x)-(A.x-B.x)*(C.x*D.y-C.y*D.x))/under;
    ld y = ((A.x*B.y-A.y*B.x)*(C.y-D.y)-(A.y-B.y)*(C.x*D.y-C.y*D.x))/under;
    cout << fixed;
    cout.precision(16);
    cout << x << ' ' << y;
}
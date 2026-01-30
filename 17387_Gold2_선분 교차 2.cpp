#include <bits/stdc++.h>

using namespace std;
using ll = long long;

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
    cout << isIntersect(A,B,C,D);
}
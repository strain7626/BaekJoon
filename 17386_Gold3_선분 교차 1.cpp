#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct pos{ll x,y;};
struct line{pos s,e;};

ll CCW(pos A,pos B,pos C) {
		return (B.x-A.x)*(C.y-B.y)-(C.x-B.x)*(B.y-A.y);
}

bool isIntersect(line l1,line l2) {
    return CCW(l1.s,l1.e,l2.s)*CCW(l1.s,l1.e,l2.e)<0&&CCW(l2.s,l2.e,l1.s)*CCW(l2.s,l2.e,l1.e)<0;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    line l1,l2;
    cin>>l1.s.x>>l1.s.y>>l1.e.x>>l1.e.y;
    cin>>l2.s.x>>l2.s.y>>l2.e.x>>l2.e.y; 
    cout << isIntersect(l1,l2);
}
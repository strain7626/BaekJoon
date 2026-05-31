#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

const ll MXN=1e5+1;

int N,ptr;
ll a[MXN],b[MXN],dp[MXN];

struct Line {
    ll m,b;
    double x;
    Line(ll _m,ll _b,double _x):m(_m),b(_b),x(_x){};
    ll f(ll x) {return m*x+b;}
};

vector<Line> lines;

double isIntersect(Line& a, Line& b) {return (double)(b.b - a.b) / (a.m - b.m);}

void addLine(ll m,ll b) {
    Line a(m,b,-1e18);
    if (lines.empty()) {
        lines.push_back(a);
        return;
    }
    while (!lines.empty()) {
        Line top=lines.back();
        double x=isIntersect(top, a);
        if (x<=top.x) lines.pop_back(); else break;
    }
    a.x=isIntersect(lines.back(),a);
    lines.push_back(a);
    if(ptr>=lines.size()) ptr=lines.size()-1;
    return;
}

ll query(ll x) {
    while(ptr<lines.size()-1&&lines[ptr+1].x<x) ++ptr;
    return lines[ptr].f(x);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin>>N;
    for(int i=0;i<N;i++) cin>>a[i];
    for(int i=0;i<N;i++) cin>>b[i];
    dp[0]=0;addLine(b[0],dp[0]);
    for(int i=1;i<N;i++) {
        dp[i]=query(a[i]);
        addLine(b[i],dp[i]);
    }
    cout<<dp[N-1]<<'\n';
    return 0;
}
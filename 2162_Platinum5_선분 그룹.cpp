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

int N,uni[3000],cnt[3000];
pos P[3000][2];

int uni_find(int now) {
    if (uni[now]==now) return now;
    return uni[now]=uni_find(uni[now]);
}


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
    
    
    cin >> N;
    for (int i=0;i<N;i++) uni[i]=i;
    for (int i=0;i<N;i++) cin>>P[i][0].x>>P[i][0].y>>P[i][1].x>>P[i][1].y;
    for (int i=0;i<N;i++) for (int j=i+1;j<N;j++) if (isIntersect(P[i][0],P[i][1],P[j][0],P[j][1])) uni[uni_find(i)]=uni[uni_find(j)];

    int ans=0;
    for (int i=0;i<N;i++) {
        ans+=(uni[i]==i);
        cnt[uni_find(i)]++;
    }
    cout << ans << '\n' << *max_element(cnt,cnt+N);
}
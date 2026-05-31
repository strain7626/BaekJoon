#include <bits/stdc++.h>

using namespace std;
using ll=long long;

struct pos{ll x,y,s;};

int N,M;
pos S[100000],O={0,0,0};

ll ccw(pos A,pos B,pos C) {return (B.x-A.x)*(C.y-A.y)-(B.y-A.y)*(C.x-A.x);}
ll dist(pos A,pos B) {return (B.x-A.x)*(B.x-A.x)+(B.y-A.y)*(B.y-A.y);}
bool half(pos A) {return A.y<0||(A.y==0&&A.x<0);}

ll solve() {
    ll P,res=0,sum=0;cin>>P;

    for(int l=0,r=0,cnt=0;r<N;r++,cnt--) {
        pos tmp={-S[r].y,S[r].x,0}; 
        while(cnt<N&&ccw(O,S[r],S[l])>=0&&ccw(O,tmp,S[l])<=0) sum+=(dist(O,S[l])>P?0:S[l].s),l=(l+1)%N,cnt++;
        res=max(res,sum);
        sum-=dist(O,S[r])>P?0:S[r].s;
    }

    return res-P;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    cin>>N>>M;
    for(int i=0;i<N;i++) cin>>S[i].x>>S[i].y>>S[i].s;
    sort(S,S+N,[](pos A,pos B){
        if(half(A)!=half(B)) return half(A)<half(B);
        return ccw(O,A,B)?ccw(O,A,B)>0:dist(O,A)<dist(O,B);
    });

    ll ans=-1e18;
    for(int i=0;i<M;i++) ans=max(ans,solve());
    cout<<ans;
}
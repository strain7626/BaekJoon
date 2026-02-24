#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll EEA(ll a,ll b,ll &x,ll &y) {
    ll g=a;x=1,y=0;
    if(b) g=EEA(b,a%b,y,x),y-=a/b*x;
    return g;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    ll a,b,x,y,T;cin>>T;while(T--) {
        cin>>a>>b;
        if(a==1&&b==1) {cout<<2<<'\n';continue;}
        if(b==1) {
            if(a==1e9) {cout<<"IMPOSSIBLE\n";continue;}
            else {cout<<a+1<<'\n';continue;}
        }
        if(a==1) {cout<<1<<"\n";continue;}
    
        if(EEA(a,b,x,y)!=1) cout<<"IMPOSSIBLE\n";
        else cout<<(y+a)%a<<'\n';
    }
}
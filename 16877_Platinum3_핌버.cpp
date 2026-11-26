#include <bits/stdc++.h>
#define all(x) (x).begin(),(x).end()

using namespace std;

const int MX=3e6+1;
int N,num[MX],fib[40]={1,2};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    for(int i=2;i<40;i++) fib[i]=fib[i-1]+fib[i-2];
    for(int i=1;i<MX;i++) {
        unsigned u=0;
        for(int f:fib) if(i-f<0) break; else u|=1u<<num[i-f];
        num[i]=__builtin_ctz(~u);
    }

    cin>>N;

    int ans=0;
    while(N--) { int P; cin>>P; ans^=num[P]; }
    cout<<(ans?"koosaga":"cubelover");
}
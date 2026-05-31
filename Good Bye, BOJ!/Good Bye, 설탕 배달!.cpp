#include <bits/stdc++.h>

using namespace std;
using ll=long long;

int N;
ll a,b,c,p,A,B,C,P;

bool solve() {
    cin>>N;
    A=B=C=P=0;bool flag=1;
    for(int i=0;i<N;i++) {
        cin>>a>>b>>c>>p;
        if(A<a) P+=a-A,A=a;
        if(B<b) P+=b-B,B=b;
        if(C<c) P+=c-C,C=c;
        if(P>=p) flag=0;
        P++;
    }
    return flag;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int T;cin>>T;while(T--) cout<<(solve()?"YES\n":"NO\n");
}
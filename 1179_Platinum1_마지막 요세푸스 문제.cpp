#include <bits/stdc++.h>

using namespace std;
using ll=long long;

ll N,K,ans,NN=1;

int main() {
    cin.tie(0)->sync_with_stdio(0);

	cin>>N>>K;
	
	if(K==1) {cout<<N;return 0;}

    while(1) {
        ll x=(NN-ans-1)/(K-1)+1;
        if(NN+x>N){ans+=(N-NN)*K;break;}
        ans=(ans+K*x)%(NN+x);
        NN+=x;
    }
    cout<<ans+1;
}
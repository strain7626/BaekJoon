#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int a,b;cin>>a>>b;
    if(bitset<32>(b).count()!=1) {cout<<-1;return 0;}

    string ans;
    while(b/=2) {
        while(a>b*2) a-=b*2,ans+='G';
        ans+='K';
    }

    reverse(ans.begin(),ans.end());
    cout<<'G'<<ans;
}
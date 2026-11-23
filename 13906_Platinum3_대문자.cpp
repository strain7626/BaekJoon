#include <bits/stdc++.h>

using namespace std;

const int MOD=1e9+7;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    string s; cin>>s;

    int dp[1001]={0};
    for(int i=s.size()-1;i--;) {
        int cnt[26]={0};
        for(int j=i;j<s.size();j++) if(++cnt[s[j]-'a']==3) dp[i]=(dp[i]+dp[j+1]+1)%MOD;
    }
    for(int i=0;i<s.size();i++) cout<<dp[i];
    cout<<dp[0];
}
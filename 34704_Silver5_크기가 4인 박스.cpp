#include <bits/stdc++.h>

using namespace std;

int N,cnt[5],ans;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin>>N;
    for(int i=0,x;i<N;i++) cin>>x,cnt[x]++;

    ans+=cnt[4];
    ans+=cnt[3];
    cnt[1]-=min(cnt[1],cnt[3]);
    ans+=cnt[2]/2;
    cnt[1]+=(cnt[2]%2)*2;
    ans+=(cnt[1]+3)/4;
    cout<<ans;
}
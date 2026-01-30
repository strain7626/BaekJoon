#include <bits/stdc++.h>
using namespace std;

int N,cnt[101];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N;
    for (int i=0;i<N*3;i++) {
        int x;cin>>x;
        cnt[x]=(cnt[x]?-1:i/3+1);
    }

    int ans=0;
    for (int i=100;i>0;i--) for (int j=i-1;j>0;j--) for (int k=j-1;k>0;k--) {
        int a=cnt[i],b=cnt[j],c=cnt[k];
        cnt[i]=(a?-1:N+1),cnt[j]=(b?-1:N+1),cnt[k]=(c?-1:N+1);
        for (int n=100;n>0;n--) {
            if (0<cnt[n]&&cnt[n]<=N+1) {ans+=cnt[n]==N+1;break;}
        }
        cnt[i]=a,cnt[j]=b,cnt[k]=c;
    }
    cout << ans;
}
#include <bits/stdc++.h>

using namespace std;

int N,Q,uni[600002],cnt[600002],ans;

int find(int n) {return (uni[n]==n?n:uni[n]=find(uni[n]));}
void merge(int a,int b) {
    a=find(a);b=find(b);
    if(a==b) return;
    if(cnt[a]>cnt[b]) swap(a,b);
    uni[a]=b;cnt[b]+=cnt[a];cnt[a]=0;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    cin>>N>>Q;
    for(int i=2;i<=N*2;i+=2) uni[i]=i,uni[i+1]=i+1,cnt[i]=1;
    for(int i=0;i<Q;i++) {
        int a,b;cin>>a>>b;
        a*=2;b*=2;
        merge(a+1,b);
        merge(a,b+1);
        if(find(a)==find(a+1)) ans+=cnt[find(a)],cnt[find(a)]=0;

        cout<<ans<<'\n';
    }
}
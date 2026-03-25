#include <bits/stdc++.h>

using namespace std;

int N,M,A[100001],chk[1000001],ans[100000];
tuple<int,int,int> query[100000];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    cin>>N;
    for(int i=1;i<=N;i++) cin>>A[i];

    cin>>M;
    for(int i=0;i<M;i++) {
        auto& [a,b,c]=query[i];
        cin>>a>>b;c=i;
    }

    int rt=sqrt(N);
    sort(query,query+M,[&](auto x,auto y){return (get<0>(x)/rt==get<0>(y)/rt?get<1>(x)<get<1>(y):get<0>(x)<get<0>(y));});

    int l=0,r=0,res=0;
    for(int i=0;i<M;i++) {
        auto [a,b,c]=query[i];
        while(r<b) res+=!chk[A[++r]]++;
        while(l>a) res+=!chk[A[--l]]++;
        while(r>b) res-=!--chk[A[r--]];
        while(l<a) res-=!--chk[A[l++]];

        ans[c]=res;
    }

    for(int i=0;i<M;i++) cout<<ans[i]<<'\n';
}
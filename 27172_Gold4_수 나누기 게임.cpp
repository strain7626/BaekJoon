#include <bits/stdc++.h>

using namespace std;

int N,A[100000],ans[1000001];
bool chk[1000001];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    cin>>N;
    for(int i=0;i<N;i++) cin>>A[i],chk[A[i]]=1;
    for(int i=0;i<N;i++) for(int x=A[i]*2;x<=1000000;x+=A[i]) if(chk[x]) ans[x]--,ans[A[i]]++;
    for(int i=0;i<N;i++) cout<<ans[A[i]]<<' ';
}
#include <bits/stdc++.h>

using namespace std;


int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int D,P,Q;cin>>D>>P>>Q;
    if(P<Q) swap(P,Q);

    int m=(P-D%P)%P;
    for(int i=0;i<=min(D/P,Q);i++) m=min(m,(Q-(D-P*i)%Q)%Q);
    cout<<D+m;
}
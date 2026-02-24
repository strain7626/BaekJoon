#include <bits/stdc++.h>

using namespace std;

int M,N,Q,a,ans[1001];

int main() {
    cin>>M>>N>>Q;
    for (int i=0;i<N;i++) cin>>a;

    for (int i=1;i<=M;i++) {
        cout<<"? "<<i<<' '<<i<<endl;
        cin>>a;ans[i]=(a==1?2:1);
    }

    cout<<"! ";
    for (int i=1;i<=N;i++) cout<<(ans[i]?ans[i]:1)<<' ';
    cout<<endl;
}
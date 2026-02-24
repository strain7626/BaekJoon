#include <bits/stdc++.h>

using namespace std;

int main() {
    int t,n,k,A[50];cin>>t;while(t--){
        cin>>n>>k;
        memset(A,0,50);
        for (int i=0;i<k;i++) cin>>A[i];
        cout<<n<<' '<<(A[0]==1?k-1:k+1)<<'\n';
        if (A[0]!=1) cout<<"1 ";
        for (int i=(A[0]==1);i<k;i++) cout<<A[i]<<' ';
        cout<<'\n';
    }
}
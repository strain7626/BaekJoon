#include <bits/stdc++.h>

using namespace std;

long long N,A[5000],m=3e9,ans[3];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    cin>>N;
    for(int i=0;i<N;i++) cin>>A[i];
    sort(A,A+N);

    for(int i=0;i<N-2;i++) {
        int j=i+1,k=N-1;
        while(j<k) {
            long long sum=abs(A[i]+A[j]+A[k]);
            if(sum<m) m=sum,ans[0]=A[i],ans[1]=A[j],ans[2]=A[k];
            if(abs(A[i]+A[j+1]+A[k])<abs(A[i]+A[j]+A[k-1])) j++; else k--;
        }
    }

    cout<<ans[0]<<' '<<ans[1]<<' '<<ans[2];
}
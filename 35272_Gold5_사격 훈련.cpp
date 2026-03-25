#include <bits/stdc++.h>

using namespace std;

int N,C[21][21];
double a,b,A[21],B[21],ans;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin>>N>>a>>b;
    
    for(int i=0;i<=N;i++) {
        C[i][0]=C[i][i]=1;
        for(int j=1;j<i;j++) C[i][j]=C[i-1][j-1]+C[i-1][j];
    }
    
    A[0]=B[0]=1;
    for(int i=0;i<N;i++) B[0]*=1-b;

    for(int i=1;i<=N;i++) B[i]=B[i-1]/(1-b)*b;
    for(int i=0;i<=N;i++) ans+=i*(B[i]*=C[N][i]);
    
    for(int i=1;i<=N;i++) {
        A[i]=A[i-1]*a;
        for(int j=0;j<i;j++) A[j]*=1-a;
        double tmp=0;
        for(int j=0;j<=N;j++) for(int k=0;k<=j;k++) tmp+=j*(A[k]*C[i][k]*B[j-k]);
        ans=max(tmp,ans);
    }
    cout.precision(16);
    cout<<ans;
}
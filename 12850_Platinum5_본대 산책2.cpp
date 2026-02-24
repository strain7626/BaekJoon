#include <bits/stdc++.h>
#define MOD 1000000007

using namespace std;
using mat=vector<vector<long long>>;

mat operator*(mat &A,mat &B) {
    mat C(8,vector<long long>(8));
    for(int i=0;i<8;i++) for(int j=0;j<8;j++) for(int k=0;k<8;k++) C[i][j]=(C[i][j]+A[i][k]*B[k][j])%MOD;
    return C;
}

mat A(8,vector<long long>(8)),B={
    {0,1,1,0,0,0,0,0},
    {1,0,1,1,0,0,0,0},
    {1,1,0,1,1,0,0,0},
    {0,1,1,0,1,1,0,0},
    {0,0,1,1,0,1,1,0},
    {0,0,0,1,1,0,0,1},
    {0,0,0,0,1,0,0,1},
    {0,0,0,0,0,1,1,0}
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int D;cin>>D;
    A[0][0]=1;
    while(D>0) {
        if(D&1) A=A*B;
        B=B*B;
        D>>=1;
    }
    cout<<A[0][0];
}
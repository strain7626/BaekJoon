#include <bits/stdc++.h>

using namespace std;

int N,DP[5][5],tmp[5][5];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    for(int i=0;i<5;i++) for(int j=0;j<5;j++) DP[i][j]=1e9;
    DP[0][0]=0;
    
    while(cin>>N&&N) {
        for(int i=0;i<5;i++) for(int j=0;j<5;j++) tmp[i][j]=1e9;
        for(int i=0;i<5;i++) for(int j=0;j<5;j++) {
            if(i!=N) tmp[i][N]=min(tmp[i][N],DP[i][j]+(j==0?2:j==N?1:(j+N)%2?3:4));
            if(j!=N) tmp[N][j]=min(tmp[N][j],DP[i][j]+(i==0?2:i==N?1:(i+N)%2?3:4));
        }
        for(int i=0;i<5;i++) for(int j=0;j<5;j++) DP[i][j]=tmp[i][j];
    }

    int m=1e9;
    for(int i=0;i<5;i++) for(int j=0;j<5;j++) m=min(m,DP[i][j]);
    cout<<m;
}
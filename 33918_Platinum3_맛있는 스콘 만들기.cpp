#include <bits/stdc++.h>

using namespace std;

int N,M,C,D, DP[201][25001];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    cin>>N>>M>>C>>D;
    for(int i=1;i<=N;i++){
        int b;cin>>b;
        for (int r=1;r<=C;r++){
            deque<int>DQ;
            for (int k=-D+r;k<=M;k+=C) {
                if(k+D<=M){
                    while(!DQ.empty()&&DP[i-1][k+D]<=DP[i-1][DQ.back()])DQ.pop_back();
                    DQ.push_back(k+D);
                }
                if(DQ.front()<k-D)DQ.pop_front();

                if(k<1)continue;
                DP[i][k]=DP[i-1][DQ.front()]+abs(b-k);
            }
        }
    }

    cout<<N*M-*min_element(DP[N]+1,DP[N]+M+1);
}
#include <bits/stdc++.h>

using namespace std;
typedef tuple<int,int,string,string> CDSE;

int N,ans;
vector<CDSE> A[15],B;

bool check(int C1,int D1,string S1,string E1) {
    for(auto [C2,D2,S2,E2]:B) if(D1==D2&&!(E1<=S2||E2<=S1)) return 0;
    return 1;
}

int DFS(int i,int cnt) {
    if(i==N) return cnt==22;
    int res=DFS(i+1,cnt);
    for(auto [C,D,S,E]:A[i]) if(check(C,D,S,E)){
        B.push_back({C,D,S,E});
        res+=DFS(i+1,cnt+C);
        B.pop_back();
    }
    return res;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    cin>>N;
    for(int i=0;i<N;i++) {
        int T;cin>>T;
        while(T--) {
            int C,D;string S,E;cin>>C>>D>>S>>E;
            A[i].push_back({C,D,S,E});
        }
    }

    cout<<DFS(0,0);
}
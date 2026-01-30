#include <bits/stdc++.h>

using namespace std;

int N,ans=1,C[200001];
vector<int> E[200001];

int DFS(int X) {
    C[X]=1;
    
    set<int> S;
    for (int &i:E[X]) S.insert(C[i]);
        
    while (S.count(C[X])) C[X]++;

    int res=C[X];
    for (int &i:E[X]) if (!C[i]) res=max(res,DFS(i));
    return res;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin>>N;for(int i=0;i<N;i++){
        int a,b;cin>>a>>b;
        E[a].push_back(b);
        E[b].push_back(a);
    }
    cout << DFS(1);
}
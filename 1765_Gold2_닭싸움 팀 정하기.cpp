#include <bits/stdc++.h>

using namespace std;

int N,M,uni[1001];
bool vis[1001];
vector<int> F[1001],E[1001];

int uni_find(int n) {return (n==uni[n]?n:uni[n]=uni_find(uni[n]));}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    cin>>N>>M;
    while(M--) {
        char T;int p,q;cin>>T>>p>>q;
        if(T=='F') F[p].push_back(q),F[q].push_back(p);
        else       E[p].push_back(q),E[q].push_back(p);
    }
    for(int i=1;i<=N;i++) uni[i]=i;

    for(int i=1;i<=N;i++) if(uni[i]==i) {
        queue<int> Q;Q.push(i);
        while(!Q.empty()) {
            for(int j:F[Q.front()]) if(uni[j]==j) {
                uni[j]=i;
                Q.push(j);
            }
            Q.pop();
        } 
    }

    for(int i=1;i<=N;i++) if(!vis[i]) {
        vis[i]=1;
        if (E[i].empty()) continue;
        int T1=uni_find(i),T2=uni_find(E[i][0]);
        queue<int> Q;Q.push(i);
        while(!Q.empty()) {
            for(int j:E[Q.front()]) if(!vis[j]) {
                vis[j]=1;
                uni[uni_find(j)]=(uni_find(Q.front())==T1?T2:T1);
                Q.push(j);
            }
            Q.pop();
        } 
    }

    int cnt=0;
    for(int i=1;i<=N;i++) cnt+=(uni[i]==i);
    cout<<cnt;
}
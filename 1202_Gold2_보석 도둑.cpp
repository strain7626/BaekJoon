#include <bits/stdc++.h>
#define MAXN 300000
using namespace std;


int N, K, M[MAXN], V[MAXN], C[MAXN], value[MAXN];
struct cmp {
    bool operator()(int a, int b) {
        return V[a] < V[b];
    }
};

priority_queue<int,vector<int>,cmp> PQ_N;

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    cin >> N >> K;
    for (int i = 0; i < N; i++) {cin >> M[i] >> V[i];PQ_N.push(i);}
    for (int i = 0; i < K; i++) cin >> C[i];


    sort(C, C+K);
    
    for (int i = K-1; i >= 0; i--) {
        while (M[PQ_N.top()] > C[i]) PQ_N.pop();
        value[i] = V[PQ_N.top()];
        PQ_N.pop();
    }

    int ans = 0;
    for (int i = 0; i < K; i++) ans += value[i]; 
    cout << ans;
}
#include <bits/stdc++.h>

using namespace std;
using pii = pair<int,int>;

struct cmp {
    bool operator() (pii a, pii b) {
        return a.second>b.second;
    }
};

int C,N,T[20000];
pii AB[20000];
priority_queue<pii,vector<pii>,cmp> PQ;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> C >> N;
    for (int i=0;i<C;i++) cin >> T[i]; sort(T,T+C);
    
    for (int i=0;i<N;i++) cin >> AB[i].first >> AB[i].second; sort(AB,AB+N);

    int idx=0,ans=0;
    for (int i=0;i<C;i++) {
        while (idx<N&&AB[idx].first<=T[i]) PQ.push(AB[idx++]);
        while (!PQ.empty()&&PQ.top().second<T[i]) PQ.pop();
        if (!PQ.empty()) ans++,PQ.pop();
    }
    cout << ans;
}
#include <bits/stdc++.h>

using namespace std;


int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int N, L; cin >> N >> L;
    priority_queue<pair<int,int>> PQ;

    for (int i = 0; i < N; i++) {
        int x; cin >> x;
        PQ.push({-x,i});
        
        while (PQ.top().second < i-L+1) PQ.pop();
        cout << -PQ.top().first << ' '; 
    }
    
}
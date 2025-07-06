#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    int T; cin >> T;
    while (T--) {
        int N; cin >> N;
        
        vector<int> C(N);
        for (int &i : C) cin >> i;

        vector<vector<int>> DP(N, vector<int>(N));
        queue<pair<int,int>> Q;
        Q.push({0,N-1});

        while(!Q.empty()) {
            int i = Q.front().first, j = Q.front().second;
            
        }


    }

}
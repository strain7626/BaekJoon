#include <bits/stdc++.h>

using namespace std;

int N, M;
pair<int,int> A[100], B[100];
vector<int> ans;

bool cmp(pair<int,int>& X, pair<int,int>& Y) {
    return (X.first == Y.first ? (X.second < Y.second) : (X.first > Y.first));
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N;
    for (int i = 0; i < N; i++) {
        int x; cin >> x;
        A[i] = {x,i};
    }
    cin >> M;
    for (int i = 0; i < M; i++) {
        int x; cin >> x;
        B[i] = {x,i};
    }
    sort(A,A+N,cmp); sort(B,B+M,cmp);

    int n = 0, m = 0, idxA = 0, idxB = 0;
    while (n<N && m<M) {
        if (A[n].first > B[m].first) { n++; continue; }
        if (A[n].first < B[m].first) { m++; continue; }
        if (!ans.empty()) {
            if (A[n].second < idxA) { n++; continue; }
            if (B[m].second < idxB) { m++; continue; }
        }
    
        ans.push_back(A[n].first);
        idxA = A[n++].second; idxB = B[m++].second;
    } 

    if (ans.empty()) cout << 0;
    else {
        cout << ans.size() << '\n';
        for (int& i : ans) cout << i << ' ';
    }
}
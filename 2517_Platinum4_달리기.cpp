#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

vector<int> T;
vector<pair<int,int>> A;

void update(int n, int s, int e, int idx, int diff) {
    if (idx < s || idx > e) return;
    T[n] += diff;
    if (s == e) return;
    update(n*2, s, (s+e)/2, idx, diff);
    update(n*2+1, (s+e)/2+1, e, idx, diff);
}

int sum(int n, int s, int e, int l, int r) {
    if (e<l || r<s) return 0;
    if (l<=s && e<=r) return T[n];
    return sum(n*2, s, (s+e)/2, l, r) + sum(n*2+1, (s+e)/2+1, e, l, r);
}

int main() {
    int N; cin >> N; A.resize(N);
    for (int i = 0; i < N; i++) {
        int x; cin >> x;
        A[i] = {x,i};
    }

    sort(A.begin(), A.end());
    for (int i = 0; i < N; i++) A[i].first = i;

    T.resize(1 << ((int)ceil(log2(N))+1));
    for (int i = N-1; i >= 0; i--) {
        A[i] = {A[i].second, sum(1, 0, N-1, 0, A[i].second)+1};
        update(1, 0, N-1, A[i].first, 1);
    }

    sort(A.begin(), A.end());
    for (auto& a : A) cout << a.second << '\n';
    
}
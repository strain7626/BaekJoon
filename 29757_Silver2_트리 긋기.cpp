#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, ans[1000];
pair<int,int> P[1001];

bool cmp(int a, int b) {
    pair<int,int> A = P[a]; pair<int,int> B = P[b];
    if (A.first == B.first) return A.second < B.second;
    return A.first < B.first;
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) ans[i] = i+1;
    for (int i = 1; i <= N; i++) cin >> P[i].first >> P[i].second;
    sort(ans, ans+N, cmp);

    for (int i = 0; i < N-1; i++) cout << ans[i] << ' ' << ans[i+1] << '\n';
}
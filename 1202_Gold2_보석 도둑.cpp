#include <iostream>
#include <algorithm>

using namespace std;

int N, K, C[300000];
pair<int,int> MV[300000];

bool cmp(pair<int,int> A, pair<int,int> B) {
    
}

int main() {
    cin >> N >> K;
    for (int i = 0; i < N; i++) cin >> MV[i].first >> MV[i].second;
    for (int i = 0; i < K; i++) cin >> C[i];

    sort(MV, cmp);
}
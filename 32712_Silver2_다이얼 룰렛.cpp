#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int N, K;
vector<int> A, S;

int main() {
    cout.tie(0);cin.tie(0);ios::sync_with_stdio(0);

    cin >> N >> K;
    A.resize(N); S.resize(N);
    for (int &a : A) cin >> a;
    S[0] = A[0];
    for (int i = 1; i < N; i++) S[i] = S[i-1]+A[i]; 

    int ans = 0;



    cout << ans;
}
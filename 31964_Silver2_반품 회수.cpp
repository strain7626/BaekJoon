#include <iostream>
#include <algorithm>
#define INF 3000
using namespace std;

int N, X[INF], T[INF];
int ans;

int main() {
    cin >> N;
    for (int i=0;i<N;i++) cin >> X[i];
    for (int i=0;i<N;i++) cin >> T[i];

    // 가장 먼 곳 부터 가서 받아옴
    ans = max(X[N-1], T[N-1]);
    
    // 거리 또는 시간
    for (int i = N-2; i >= 0; i--) {
        ans = max(ans+X[i+1]-X[i], T[i]);
    }

    // 마지막 택배 회사까지 거리
    ans += X[0];

    cout << ans;
}
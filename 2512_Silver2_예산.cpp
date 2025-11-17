#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    int N; cin >> N; vector<int> B(N);
    for (int i = 0; i < N; i++) cin >> B[i];
    int L; cin >> L;

    int ans = 0;
    int s = 1, e = 1e9;
    while (s <= e) {
        int m = (s+e)/2;
        int sum = 0;
        for (int i : B) sum += min(i, m);
        if (sum <= L) { s = m+1; ans = m; }
        else e = m-1;
    }

    int tmp = 0;
    for (int i : B) tmp = max(tmp, i);
    cout << min(tmp, ans);
}
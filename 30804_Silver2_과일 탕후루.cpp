#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> A;
map<int,int> cnt;

int main() {
    cin.tie(0);ios_base::sync_with_stdio(0);

    cin >> N; A.resize(N);
    for (int& a : A) cin >> a;

    int ans = 0;
    int p1=0, p2=1; cnt[A[0]] = 1;

    while (p2 <= N) {
        if (cnt.size() > 2) {
            if (!--cnt[A[p1]]) cnt.erase(A[p1]);
            p1++;
            continue;
        }

        ans = max(ans,p2-p1);
        cnt[A[p2++]]++;
    }

    cout << ans;
}
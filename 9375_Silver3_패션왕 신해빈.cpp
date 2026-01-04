#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    
    int T; cin >> T; while (T--) {
        map<string, int> M;
        int N; cin >> N; while (N--) {
            string s1, s2; cin >> s1 >> s2;
            if (M.count(s2)) M[s2]++;
            else M[s2] = 2;
        }

        int ans = 1;
        for (auto& m : M) ans *= m.second;
        cout << ans-1 << '\n';
    }
}
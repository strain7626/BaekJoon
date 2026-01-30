#include <bits/stdc++.h>

using namespace std;

int N;
vector<string> ans = {
    "  *  ",
    " * * ",
    "*****"
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    cin >> N;
    for (int T = 3; T < N; T*=2) {
        string preset(T, ' ');
        for (int i = 0; i < T; i++) {
            ans.push_back(ans[i]+' '+ans[i]);
            ans[i] = preset + ans[i] + preset;
        }
    }

    for (auto& x : ans) cout << x << '\n';
}
#include <bits/stdc++.h>

using namespace std;

int solution(string s1, string s2) {
    if (s1 == s2) return 0;

    for (int i = 0; i < s1.size(); i++) {
        if (s1[i] == s2[i]) continue;

        int L = s1.size();
        if (s1.substr(0,i)+s1.substr(i+1) == s2.substr(0,L-i-1)+s2.substr(L-i)) return 1;
        if (s2.substr(0,i)+s2.substr(i+1) == s1.substr(0,L-i-1)+s1.substr(L-i)) return 1;
        break;
    }

    return 2;
}

int main() {
    cin.tie(0);ios_base::sync_with_stdio(0);
    
    int T; cin >> T;
    while (T--) {
        string S; cin >> S;
        string _S = S; reverse(_S.begin(), _S.end());
        cout << solution(S, _S) << '\n';
    }
}

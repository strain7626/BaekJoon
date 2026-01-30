#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N,x;cin>>N;
    vector<string> S;

    for (int i=0;i<N;i++) {
        cin>>x;S.resize(x);
        for (auto &s:S) cin>>s;
    }

    cout << x;
    for (auto &s:S) cout << s << '\n';
}
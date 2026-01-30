#include <bits/stdc++.h>

using namespace std;

int main() {
    int S;cin>>S;
    vector<pair<int,int>> ans;
    if (S%4763) {cout << 0; return 0;}
    S/=4763;
    for (int i=0;i<=200;i++) for (int j=0;j<=200;j++) {
        if (i*508+j*212==S||i*108+j*212==S||i*508+j*305==S||i*108+j*305==S) ans.push_back({i,j});
    }
    cout << ans.size() << '\n';
    for (auto [i,j]:ans) cout << i << ' ' << j << '\n';
}
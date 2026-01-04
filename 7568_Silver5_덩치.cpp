#include <bits/stdc++.h>

using namespace std;

int N;
vector<pair<int,int>> xy;
vector<int> ans;

int main() {
    cin >> N; xy.resize(N); ans.resize(N);
    for (auto& i : xy) cin >> i.first >> i.second;

    for (auto& i : xy) {
        int cnt = 1;
        for (auto& j : xy) if (i.first < j.first && i.second < j.second) cnt++;
        cout << cnt << ' ';
    }

}
#include <bits/stdc++.h>

using namespace std;

int n;
string p, X;
deque<int> DQ;

void solve() {
    bool R = 0;

    for (char c : p) {
        if (c == 'R') R=!R;
        if (c == 'D') {
            if (DQ.empty()) { cout << "error\n"; return; }
            if (R) DQ.pop_back(); else DQ.pop_front(); 
        }
    }
    
    cout << '[';
    while(!DQ.empty()) { 
        if (R) { cout << DQ.back(); DQ.pop_back(); } 
        else { cout << DQ.front(); DQ.pop_front(); }
        if(!DQ.empty()) cout << ','; 
    }
    cout << "]\n";
}

int main() {
    cin.tie(0);ios::sync_with_stdio(0);

    int T; cin >> T;
    while (T--) {
        cin >> p >> n >> X;
        string tmp;
        for (char x : X) {
            if (x>='0' && x<='9') tmp += x; 
            else if (!tmp.empty()) { DQ.push_back(stoi(tmp)); tmp.clear(); }
        }
        solve();
    }
}
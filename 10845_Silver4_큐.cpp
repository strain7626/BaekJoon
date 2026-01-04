#include <bits/stdc++.h>

using namespace std;


int main() {
    cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);

    queue<int> Q;
    int N; cin >> N;
    while (N--) {
        string S; cin >> S;
        if (S == "push") {
            int x; cin >> x;
            Q.push(x);
        } else if (S == "pop") {
            if (Q.empty()) cout << -1 << '\n';
            else { 
                cout << Q.front() << '\n';
                Q.pop();
            }
        } else if (S == "size") {
            cout << Q.size() << '\n';
        } else if (S == "empty") {
            cout << Q.empty() << '\n';
        } else if (S == "front") {
            if (Q.empty()) cout << -1 << '\n';
            else cout << Q.front() << '\n';
        } else if (S == "back") {
            if (Q.empty()) cout << -1 << '\n';
            else cout << Q.back() << '\n';
        }
    }   
}
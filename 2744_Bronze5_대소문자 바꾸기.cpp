#include <bits/stdc++.h>
using namespace std;

int main() {
    string S; cin >> S;
    int t = 'a'-'A';
    for (char c : S) {
        cout << (c>='a' ? char(c-t) : char(c+t));
    }
}
#include <bits/stdc++.h>
#define MOD 1000000
using namespace std;

int DP[5000];

int main() {
    string S; cin >> S;
    S = ' '+S;

    DP[0] = 1;
    if (S[1]-'0') DP[1] = 1;
    else {cout << 0; exit(0);}

    for (int i = 2; i < S.length(); i++) {
        bool flag = true;

        int cmp = S[i]-'0';
        if (cmp != 0) {DP[i] = DP[i-1];flag=0;}
        cmp += 10*(S[i-1]-'0');
        if (cmp >= 10 && cmp <= 26) {DP[i] += DP[i-2];flag=0;}

        DP[i] %= MOD;
        if (flag) {cout << 0; exit(0);}
    }

    cout << DP[S.length()-1];
}
#include <bits/stdc++.h>
using namespace std;

int N;
string ori_S;
int ans;

int calc(int num1, int num2, char cal) {
    if (cal == '+') return num1 + num2;
    if (cal == '-') return num1 - num2;
    return num1 * num2;
}

void Solve(int val, string S) {
    if (S.size() == 0) {
        ans = max(ans,val);
        return;
    }

    int nxt_val = calc(val,S[1]-'0',S[0]);
    Solve(nxt_val,S.substr(2));

    if (S.size() == 2) return;
    nxt_val = calc(val,calc(S[1]-'0',S[3]-'0',S[2]),S[0]);
    Solve(nxt_val,S.substr(4));
}

int main() {
    cin >> N;
    cin >> ori_S;   

    ans = -2e9;
    Solve(ori_S[0]-'0', ori_S.substr(1));
    cout << ans;
}
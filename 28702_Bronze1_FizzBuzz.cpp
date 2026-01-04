#include <bits/stdc++.h>

using namespace std;

int main() {

    int ans;
    for (int i = 0; i < 3; i++) {
        string S; cin >> S;
        if (S == "Fizz" || S == "Buzz" || S == "FizzBuzz") continue;
        ans = (3-i) + stoi(S);
    }

    if (ans%3 == 0 && ans%5 == 0) cout << "FizzBuzz";
    else if (ans%3 == 0) cout << "Fizz";
    else if (ans%5 == 0) cout << "Buzz";
    else cout << ans;
}
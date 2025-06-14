#include <bits/stdc++.h>
using namespace std;

string S1, S2;
stack<char> ans;
stack<int> idx; 

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    cin >> S1 >> S2;
    ans.push(' ');
    idx.push(0);

    for (char c : S1) {
        ans.push(c);
        if (c == S2[idx.top()]) idx.push(idx.top()+1);
        else idx.push(c == S2[0]);

        if (idx.top() == S2.size()) 
            for (int i = 0; i < S2.size(); i++) {
                ans.pop();
                idx.pop();
            }
    }

    string result;
    while (ans.size() > 1) {
        result += ans.top();
        ans.pop();
    }
    reverse(result.begin(),result.end());

    if (result.size() == 0) cout << "FRULA";
    else cout << result;
}
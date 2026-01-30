#include <bits/stdc++.h>

using namespace std;

string X;
stack<char> S;

int main() {    
    cin.tie(0);
    
    cin >> X;
    for (char& x : X) {
        if ('A'<=x&&x<='Z') cout << x;
        else if (x=='(') S.push(x);
        else if (x=='*'||x=='/') {
            while (!S.empty() && (S.top()=='*'||S.top()=='/')) { cout << S.top(); S.pop(); } 
            S.push(x);
        } else if (x=='+'||x=='-') {
            while (!S.empty() && S.top()!='(') { cout << S.top(); S.pop(); }
            S.push(x);
        } else if (x==')') {
            while (S.top()!='(') { cout << S.top(); S.pop(); }
            S.pop();
        }
    }
    while (!S.empty()) { cout << S.top(); S.pop(); }
}
#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

string str;
string bomb;

typedef pair<char,int> cell;

stack<cell> S;

int main() {
    cin >> str >> bomb;

    for (char c : str) {
        if (S.empty()) {
            S.push({c,(c==bomb[0])});
        } else {
            if (c==bomb[S.top().second]) S.push({c,S.top().second+1});
            else S.push({c,(c==bomb[0])});
        }

        if (S.top().second == bomb.size()) for (int i = 0; i < bomb.size(); i++) S.pop();
    }

    string result;
    while (!S.empty()) {
        result += S.top().first;
        S.pop();
    }

    reverse(result.begin(), result.end());
    
    if (result.empty()) cout << "FRULA";
    else cout << result;
}
#include <bits/stdc++.h>

using namespace std;

int main() {
    string S; cin >> S;

    int ans = 0, t;
    for (int i = 0; i < 13; i++) 
        if (S[i] == '*') t = (i%2 ? 3 : 1); 
        else ans += (i%2 ? 3 : 1)*(S[i]-'0');
    ans = ((1000-ans)%10);

    int tmp[] = {0,7,4,3,8,5,2,9,6,3};
    cout << (t==3 ? tmp[ans] : ans);
}
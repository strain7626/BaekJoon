#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    string S;cin>>S;
    sort(S.begin(),S.end());
    reverse(S.begin(),S.end());
    cout<<S;
}
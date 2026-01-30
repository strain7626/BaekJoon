#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int s,c,o,n; cin>>s>>c>>o>>n;
    cout << min((c+o*2)/6,(s+n)/3);
}
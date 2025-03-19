#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

vector<int> pre;

void post(int begin, int end) {
    if (begin == end) return;
    
    int now = pre[begin];

    int i;
    for (i = begin+1; i < end; i++)
        if (pre[i] > now) break;

    post(begin+1, i);
    post(i,end);

    cout << now << endl;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    int a;
    while (cin >> a) {
        if (a == EOF) break;
        pre.push_back(a);
    }

    post(0, pre.size());
}
#include <bits/stdc++.h>
using namespace std;

int n;
int in[100001], post[100001];

void setTree(int inBegin, int inEnd, int postBegin, int postEnd) {
    if (inBegin == inEnd) return;

    int parent = post[postEnd-1];
    int cnt = 0;

    for (int i = inBegin; i < inEnd; i++) {
        if (in[i] == parent) break;
        cnt++;
    }

    cout << parent << " ";
    setTree(inBegin, inBegin+cnt, postBegin, postBegin+cnt);
    setTree(inBegin+cnt+1, inEnd, postBegin+cnt, postEnd-1);
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) cin >> in[i];
    for (int i = 0; i < n; i++) cin >> post[i];

    setTree(0,n,0,n);
}
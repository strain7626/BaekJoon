#include <bits/stdc++.h>

using namespace std;

int P,G,g[100001],uni[100001];

int uni_find(int now) {
    if (uni[now]==now) return now;
    return uni[now]=uni_find(uni[now]);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> G >> P;
    for (int i=0;i<P;i++) cin >> g[i];
    for (int i=1;i<=G;i++) uni[i]=i;
    
    int cnt;
    for (cnt=0;cnt<P;cnt++) if (uni_find(g[cnt])) uni[uni_find(g[cnt])]=uni[uni_find(g[cnt])-1]; else break;

    cout << cnt;
}
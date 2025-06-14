#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

vector<int> ans;
int vis[101];
int arr[101];

int DFS(int now, int t) {
    vis[now] = t;

    if (now == arr[now]) {
        ans.push_back(now);
        return 0;
    }

    if (vis[arr[now]]) {
        if (t == vis[arr[now]]) {
            ans.push_back(now);
            return arr[now];
        }
        else return 0;
    }

    int a = DFS(arr[now], t);
    
    if (!a) return 0;

    ans.push_back(now);
    if (a == now) return 0;
    return a;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    int N; cin >> N;
    for (int i = 1; i <= N; i++) cin >> arr[i];

    for (int i = 1; i <= N; i++) if (!vis[i]) DFS(i,i);
    
    sort(ans.begin(),ans.end());
    cout << ans.size() << endl;

    for (int i : ans) cout << i << endl;
}
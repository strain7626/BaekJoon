#include <bits/stdc++.h>
#define MAXN 1000000
using namespace std;

int N, Te[MAXN], Tx[MAXN];

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++) cin >> Te[i] >> Tx[i];
    sort(Te, Te+N);
    sort(Tx, Tx+N);

    int Te_point = 0, Tx_point = 0;

    int cnt = 0, ans = 0;
    pair<int,int> ansT;
    bool flag = false;

    while (Te_point < N) {

        if (Te[Te_point] == Tx[Tx_point]) {Te_point++;Tx_point++;}
        else if (Te[Te_point] < Tx[Tx_point]) {
            Te_point++;cnt++;
            if (cnt > ans) {
                ans = cnt;
                ansT.first = Te[Te_point-1];
                flag = true;
            }
        }
        else {
            Tx_point++;cnt--;
            if (flag) {
                ansT.second = Tx[Tx_point-1];
                flag = false;
            }
        }

    }

    if (flag) ansT.second = Tx[Tx_point];
    cout << ans << endl;
    cout << ansT.first << " " << ansT.second;
}   
/*

몇달 전에 단계별 문제를 포기하게 만들었던 문제인데 다시보니 풀어지네!!
이 쾌감!!!!!!!!
이거때문에PS하지 ㄹㅈㄷㄹㅈㄷ
개지려따

*/

#include <bits/stdc++.h>

using namespace std;

int n, k;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> n >> k;
    if (n==k) {
        cout << "Impossible";
        exit(0);
    }

    int cnt = n-k-1, i = 2;
    if (cnt%2) {
        cout << "2 1 ";
        cnt--;
        i = 3;
    } else cout << "1 ";
    while (cnt > 0) {
        cout << i+1 << ' ' << i << ' ';
        cnt -= 2;
        i += 2;
    } 
    while (i <= n) cout << i++ << ' ';
}
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;


int main() {
    
    int N; cin >> N;
    ll stt = 0;
    ll ans = 0;
    int arr[100000];
    bool check[100001];

    for (int i = 0; i < N; i++) cin >> arr[i];


    int s = 0, e = 0;
    while (s < N) {
        while (e < N && check[arr[e]] == 0) {
            check[arr[e]] = 1;
            e++;
        }
        check[arr[s]] = 0;
        ans += e-s;
        s++;
    }
    cout << ans;
}
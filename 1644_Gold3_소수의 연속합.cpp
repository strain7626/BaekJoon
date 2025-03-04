#include <bits/stdc++.h>
#define MAXN 4000000
using namespace std;

typedef long long ll;

int N;
bool check[MAXN+1]; // N 까지의 소수들을 구하는데 사용
vector<ll> prime; // N 까지의 소수 누적합 배열

int main() {
    cin >> N;
    prime.push_back(0);
    for (int i = 2; i <= N; i++) {
        if (check[i]) continue;
        for (int j = i+i; j <= N; j += i) check[j] = 1;
        prime.push_back(i+prime.back());
    }

    int i = 0, j = 1, ans = 0;
    while (j <= prime.size()) {
        if (prime[j] - prime[i] == N) ans++;
        if (prime[j] - prime[i] >= N) i++;
        else j++;
    }

    cout << ans;
}
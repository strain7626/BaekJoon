#include <iostream>
#include <algorithm>

using namespace std;

int n,k;
int DP[10001], Cs[101];

void Input() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> Cs[i];
        if (Cs[i] > 10000) Cs[i] = 0;
    }
    sort(Cs,Cs+n);
}

int main() {
    Input();
    
    for (int c:Cs) {
        if (c == 0) continue;

        DP[c] += 1;
        for (int i = c+1; i <= k; i++)
            DP[i] += DP[i-c];
    }

    cout << DP[k];
    return 0;
}
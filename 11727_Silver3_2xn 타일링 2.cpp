#include <iostream>

using namespace std;

int n;
long long DP[1001] = {0,1,3};

int main() {
    cin >> n;
    for (int i = 3; i <= n; i++) {
        DP[i] = (DP[i-1]+DP[i-2]*2)%10007;
    }
    cout << DP[n];
}
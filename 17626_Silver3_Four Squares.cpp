#include <iostream>
#define INF 50000
using namespace std;

int DP[INF+1];

int main() {
    for (int i = 1; i <= INF; i++) DP[i] = 2e9;
    DP[0] = 0;
    
    for (int i = 0; i <= INF; i++) {
        int x = 1;
        while (i+x*x <= INF) {
            if (DP[i]+1 < DP[i+x*x]) DP[i+x*x] = DP[i]+1;
            x++;
        }
    }

    int n; cin >> n;
    cout << DP[n];
}
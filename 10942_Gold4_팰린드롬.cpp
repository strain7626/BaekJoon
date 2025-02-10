#include <iostream>
#define endl "\n"
using namespace std;

int N, A[2001];
bool DP[2001][2001]; // i 부터 j 까지가 펠린드롬인지 아닌지

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    cin >> N;
    for (int i=1;i<=N;i++) cin >> A[i];
    
    for (int i = 1; i <= N; i++) DP[i][i] = true;
    for (int i = 1; i <= N-1; i++) DP[i][i+1] = A[i]==A[i+1];

    for (int i = 2; i < N; i++) {
        for (int j = 1; j <= N-i; j++) {
            DP[j][j+i] = (DP[j+1][j+i-1] && A[j] == A[j+i]);
        }
    }

    int M; cin >> M;
    while (M--) {
        int S,E; cin >> S >> E;
        cout << DP[S][E] << endl;
    }
}
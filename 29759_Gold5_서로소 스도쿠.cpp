#include <iostream>
#include <queue>
using namespace std;

int N, S[100][100];
bool isC[1000001];
vector<int> I[100], J[100], B[10][10], P;

bool check(int x, int i, int j) {
    for (int t : I[i]) if (t%x == 0) return 0;
    for (int t : J[j]) if (t%x == 0) return 0;
    for (int t : B[i/N][j/N]) if (t%x == 0) return 0;
    return 1;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    for (int i = 2; i <= 1000000; i++) if (!isC[i]) {
        for (int j = i+i; j <= 1000000; j+=i) isC[j] = 1;
        P.push_back(i); 
    }

    cin >> N;
    for (int i = 0; i < N*N; i++) for (int j = 0; j < N*N; j++) {
        int x; cin >> x;
        S[i][j] = x;
        if (x) {
            I[i].push_back(x);
            J[j].push_back(x);
            B[i/N][j/N].push_back(x);
        }
    }

    for (int i = 0; i < N*N; i++) { for (int j = 0; j < N*N; j++) {
        if (S[i][j]) { cout << S[i][j] << ' '; continue; }
        for (int x : P) {
            if (!check(x, i, j)) continue;
            I[i].push_back(x);
            J[j].push_back(x);
            B[i/N][j/N].push_back(x);
            cout << x << ' '; 
            break;
        }
    } cout << '\n'; }
}
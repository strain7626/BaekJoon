#include <iostream>
#include <algorithm>

using namespace std;

int N;
int values[100000][2];
int DP[100000][3];

void input() {
    cin >> N;
    for (int j = 0; j < 2; j++) for (int i = 0; i < N; i++)
        cin >> values[i][j];
}

int main() {
    int T;
    cin >> T;

    for (int t = 0; t < T; t++) {
        input(); 
        DP[0][0]=values[0][0];DP[0][1]=values[0][1];

        for (int i = 1; i < N; i++) {
            DP[i][0] = max(DP[i-1][1], DP[i-1][2]) + values[i][0];
            DP[i][1] = max(DP[i-1][0], DP[i-1][2]) + values[i][1];
            DP[i][2] = *max_element(DP[i-1],DP[i-1]+3);
        }
        cout << *max_element(DP[N-1],DP[N-1]+3) << endl;
    }

    return 0;
}   
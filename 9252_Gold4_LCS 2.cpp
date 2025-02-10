#include <iostream>
#include <algorithm>
using namespace std;

int DP[1001][1001];
pair<int,int> prevIdx[1001][1001];

int main() {
    string A; cin >> A;
    string B; cin >> B;

    for (int i = 1; i <= A.length(); i++) {
        for (int j = 1; j <= B.length(); j++) {
            if (A[i-1] == B[j-1]) {
                DP[i][j] = DP[i-1][j-1]+1;
                prevIdx[i][j] = {i,j};
            }
            else {
                DP[i][j] = max(DP[i-1][j], DP[i][j-1]);
                if (DP[i-1][j] > DP[i][j-1]) {
                    DP[i][j] = DP[i-1][j];
                    prevIdx[i][j] = prevIdx[i-1][j];
                } else {
                    DP[i][j] = DP[i][j-1];
                    prevIdx[i][j] = prevIdx[i][j-1];
                }
            }
        }
    }

    cout << DP[A.length()][B.length()] << endl;

    string result;
    pair<int,int> Idx = prevIdx[A.length()][B.length()];
    while (Idx.first != 0) {
        result += A[Idx.first-1];
        Idx = prevIdx[Idx.first-1][Idx.second-1];
    }
    reverse(result.begin(), result.end());
    cout << result;
}
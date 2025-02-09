#include <iostream>
#include <algorithm>
#include <vector>
#define endl "\n"
using namespace std;

int N, A[1000];
vector<int> DP[1000];

int main() {
    cin >> N;
    for (int i=0;i<N;i++) cin >> A[i];

    DP[0] = {A[0]};
    for (int i = 1; i < N; i++) {
        int idx = -1;
        for (int j = 0; j < i; j++) {
            if (A[i] > A[j] && DP[j].size() > DP[idx].size()) idx = j;
        }
        if (idx != -1) DP[i] = DP[idx];
        DP[i].push_back(A[i]);
    }

    int idx = 0;
    for (int i = 0; i < N; i++) {
        if (DP[i].size() > DP[idx].size()) idx = i;
    }

    cout << DP[idx].size() << endl;
    for (int i : DP[idx]) cout << i << " ";
}
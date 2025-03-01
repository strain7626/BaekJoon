#include <bits/stdc++.h>
using namespace std;

int N, A[100000];

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++) cin >> A[i];
    sort(A, A+N);

    int i = 0, j = N-1;
    pair<int,int> ans = {i,j};

    while (i < j) {
        if (abs(A[ans.first]+A[ans.second]) > abs(A[i]+A[j]))
            ans = {i,j};

        if (abs(A[i]) > abs(A[j])) i++;
        else j--;
    }

    cout << A[ans.first] << " " << A[ans.second];
}
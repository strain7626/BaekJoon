#include <bits/stdc++.h>

using namespace std;

int N, K, A[200001], num;
map<int, long long> M;

int main(){
    cin >> N >> K;

    long long cnt = 0;
    M[0] = 1;

    for (int i = 1; i <= N; i++){
        cin >> num;
        A[i] = A[i-1] + num;
        cnt += M[A[i] - K];
        M[A[i]]++;
    }
    cout << cnt;
}
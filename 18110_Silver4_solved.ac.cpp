#include <bits/stdc++.h>

using namespace std;

int N; vector<int> A;

int main() {
    cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    
    cin >> N; 
    if (N == 0) {
        cout << 0; exit(0);
    }
    A.resize(N); 
    for (int& a : A) cin >> a;

    int ps = (N*15+50)/100;
    sort(A.begin(), A.end());

    int ans = 0;
    for (int i = ps; i < N-ps; i++) ans += A[i];
    
    int t = (N-2*ps);
    cout << (ans*2+t)/t/2;
}
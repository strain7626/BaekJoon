#include <iostream>
#include <vector>

using namespace std;
   
int main() {
    cin.tie(0);ios::sync_with_stdio(0);

    int N; cin >> N;
    vector<int> A(N);
    for (int &a : A) cin >> a;

    int cnt = 0;
    for (int a : A) if (a%2) cnt++;
    
    if (N == 1 && cnt == 0) cout << 0;
    else cout << !(cnt == 2 && (A[0]%2 && A[N-1]%2));
}
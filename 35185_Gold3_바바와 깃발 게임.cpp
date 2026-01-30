#include <bits/stdc++.h>
#define MAX 200000

using namespace std;

int N, L, A[MAX+1];
string S;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N >> L >> S;

    int B=1,M=1;
    for (int i=0;i<S.size();i++) {
        if (S[i]=='L') B-=(B>1);
        else B+=(B<N);

        if (i==S.size()-1) {
            if (B <= M) break;
            cout << "WIN\n" << 1 << ' ' << B;
            return 0;
        } else M = max(M, B);
    }
    B=M=N;
    for (int i=0;i<S.size();i++) {
        if (S[i]=='L') B-=(B>1);
        else B+=(B<N);

        if (i==S.size()-1) {
            if (B >= M) break;
            cout << "WIN\n" << N << ' ' << B;
            return 0;
        } else M = min(M, B);
    }
    cout << "DEFEAT";    
}
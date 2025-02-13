#include <iostream>
#include <stack>
#define INF 1000000
using namespace std;

int N, A[INF];
stack<pair<int,int>> S; // IDX, DATA

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    cin >> N;
    for (int i=0;i<N;i++) cin >> A[i];

    for (int i = 0; i < N; i++) {
        while (!S.empty() && A[i] > S.top().second) {
            A[S.top().first] = A[i];
            S.pop();
        }
        
        S.push({i,A[i]});
        A[i] = -1;
    }

    for (int i=0;i<N;i++) cout << A[i] << " ";
}

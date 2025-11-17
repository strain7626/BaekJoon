#include <iostream>
#include <queue>
using namespace std;

int N, L;
vector<int> A, D;
priority_queue<int, vector<int>, cmp> PQ;

typedef struct {
    bool operator() (int i, int j) {
        return A[i], A[j];
    }   
} cmp;


int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> N >> L; A.resize(N), D.resize(N);
    for (int& a : A) cin >> a;
    
    for (int i = 0; i < N; i++) {
        PQ.push(i);
        while (PQ.top() <= i-L) PQ.pop();
        D[i] = PQ.top();
    }

    for (int& d : D) cout << d << ' ';
}
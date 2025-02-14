#include <iostream>
#include <algorithm>
#include <stack>
#define INF 100000
using namespace std;

int N, A[1+INF+1]; // 맨 앞과 맨 뒤는 무조건 0임
stack<int> S; // IDX
int ans;

int main() {
    cin >> N;
    for (int i=1;i<=N;i++) cin >> A[i];

    S.push(0); // S가 완전히 비우게 두지 않음. 모든 수는 0보다 크므로 여기서 while 문이 멈춤.
    for (int i = 1; i <= N+1; i++) { // 맨 뒤 0 까지 for문을 돌려서 S를 확실히 비움
        while (A[i] < A[S.top()]) {
            int temp = S.top(); S.pop();
            ans = max(ans, A[temp]*(i-S.top()-1));
        }
        S.push(i);
    }
    cout << ans;
}
#include <iostream>
#include <algorithm>

using namespace std;

//기본 입력 값들
int N,C,X[200000];

//기본 입력 함수
void Input() {
    cin >> N >> C;
    for (int i = 0; i < N; i++) cin >> X[i];

    sort(X, X+N); //집좌표를 정렬해서 거리를 쉽게 알 수 있게 함
}

//거리를 받아서 가능한지 여부 판단
bool Possible(int dis) {
    int prev = X[0], cnt = C-1;

    for (int i = 1; i < N; i++) {
        if (X[i]-prev >= dis) {
            cnt--;
            prev = X[i];
        }
        if (!cnt) return true;
    }

    return false;
}

//이분탐색으로 가능한 거리의 최댓값을 구하는 함수
int Solve() {
    int result;
    int bot = 1, top = X[N-1] - X[0];

    while (bot <= top) {
        int mid = (top+bot)/2;

        if (Possible(mid)) {
            result = mid;
            bot = mid+1;
        } else top = mid-1;
    }

    return result;
}

int main() {
    Input();
    cout << Solve();
}
#include <bits/stdc++.h>
using namespace std;

int N, 
    height[50],
    score[50]; // i 번째 건물에서 볼 수 있는 빌딩 수

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) cin >> height[i];

    for (int i = 1; i < N; i++) for (int j = 0; j < i; j++) {
        double gap = double(height[i]-height[j])/(i-j);
        bool flag = 0; // 건물 i 와 j 사이를 볼 수 없게 만드는 건물이 존재할 때 true

        for (int k = j+1; k < i; k++) {
            if (height[k] < height[j]+(k-j)*gap) continue;
            flag = 1;
            break;
        }

        if (!flag) {
            score[i]++;
            score[j]++;
        }
    }

    int ans = 0;
    for (int i = 0; i < N; i++) ans = max(ans,score[i]);
    cout << ans;
}
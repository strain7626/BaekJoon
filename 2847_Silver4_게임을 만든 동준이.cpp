#include <iostream>
using namespace std;

int N, score[100];
int ans = 0;

int main() {
    cin >> N;
    for (int i=0;i<N;i++) cin >> score[i];

    for (int i = N-2; i >= 0; i--) if (score[i] >= score[i+1]) {
        ans += score[i] - score[i+1] + 1;
        score[i] = score[i+1]-1;
    }

    cout << ans;
}
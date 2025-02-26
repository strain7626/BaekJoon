#include <bits/stdc++.h>
#define INF 1e9
using namespace std;

int N, W[16][16], DP[16][1<<16];

// 주어진 매개변수 상태에서 0으로 되돌아가기 위한 최소비용 반환
int DFS(int now, int visit) {
    if (DP[now][visit] != -1) return DP[now][visit]; // DP 활용
    if (visit == (1<<N)-1) return (W[now][0] ? W[now][0] : INF); // 모든 곳을 방문했을 때 0으로 돌아가는 길이 있으면 그 비용 반환, 없으면 INF 반환

    DP[now][visit] = INF; // 최솟값을 찾기위한 INF
    for (int nxt = 0; nxt < N; nxt++) {
        if (!W[now][nxt] || visit&(1<<nxt)) continue; // 길이 없거나, 이미 방문한 곳일 때 제외
        DP[now][visit] = min(DP[now][visit], DFS(nxt,visit|(1<<nxt)) + W[now][nxt]); // 최솟값 찾기
    }

    return DP[now][visit];
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    // 입력
    cin >> N;
    for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) cin >> W[i][j];

    // 초기화
    memset(DP,-1,sizeof(DP));

    // 어디서 시작하든 동일한 사이클임
    cout << DFS(0,1);
}
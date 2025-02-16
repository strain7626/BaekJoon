#include <iostream>

using namespace std;
typedef struct _pos {
    int x;
    int y;
    _pos(int _y, int _x) : y(_y), x(_x) {}
}pos; 

/* 핵심 아이디어 */
// 체스판을 2개로 나눠서 풀어라!
// 무슨 소용인가 싶지만 갑자기 개빨라진다.

int     N;
bool    graph[10][10],
        downCross[19], // 왼쪽 위 ~ 오른쪽 아래
        upCross[19]; // 왼쪽 아래 ~ 오른쪽 위
int     B_Cnt = 0,
        ans1 = 0,
        ans2 = 0;

// P좌표 포함, 다음 비숍 가능 위치 반환
pos nxtIdx(pos P, bool type) {
    int y = P.y, x = P.x;
    
    // 다음 비숍 가능 위치 탐색
    for (x = P.x; x < N; x+=2) if (graph[y][x] && downCross[(N-1)-y + x] && upCross[y+x]) return {y,x};
    for (y = P.y+1; y < N; y++) for (x = ((y+type)%2 ? 1 : 0); x < N; x+=2) // x = ((y+type)%2 ? 1 : 0) << 중요
        if (graph[y][x] && downCross[(N-1)-y + x] && upCross[y+x]) return {y,x};

    // 없음
    return {-1,-1};
}

void DFS(pos P, bool type) {
    // 끝
    if (P.y == -1) {
        if (type) ans1 = (B_Cnt > ans1 ? B_Cnt : ans1);
        else ans2 = (B_Cnt > ans2 ? B_Cnt : ans2);
        return;
    }

    // 비숍을 P에 둘 때
    graph[P.y][P.x] = 0;
    downCross[(N-1)-P.y + P.x] = 0;
    upCross[P.y + P.x] = 0;
    B_Cnt++;

    DFS(nxtIdx(P,type),type);

    graph[P.y][P.x] = 1;
    downCross[(N-1)-P.y + P.x] = 1;
    upCross[P.y + P.x] = 1;
    B_Cnt--;

    // 비숍을 P에 안 둘 때
    DFS(nxtIdx({P.y, P.x+2},type),type); // 2로 해줘야 정확함
}

int main() {
    cin >> N;
    for (int i=0;i<N;i++) for (int j=0;j<N;j++) cin >> graph[i][j];
    for (int i=0;i<19;i++) {downCross[i]=1;upCross[i]=1;}

    DFS(nxtIdx({0,0},0),0);
    DFS(nxtIdx({0,1},1),1);

    cout << ans1+ans2;
}
#include <iostream>
#include <queue>
#include <cmath>

using namespace std;

int N, M;
int map[8][8], t_map[8][8];
int dy[]={1,-1,0,0}, dx[]={0,0,-1,1};

void Input() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) for(int j = 0; j < M; j++)
        cin >> map[i][j];
}

bool lineout(int y, int x) {
    if (y<0||y>=N||x<0||x>=M) return true;
    else return false;
}

int Test() {
    queue<pair<int,int>> Q;
    int cnt = 0;
    //초기 바이러스 위치, 초기 안전공간
    for (int i = 0; i < N; i++) for(int j = 0; j < M; j++)
        if(t_map[i][j] == 2) Q.push({i,j});
        else if(t_map[i][j] == 0) cnt++;
    //바이러스 확산, 안전 공간 바로 체크 (간단 BFS)
    while (!Q.empty()) {
        int y=Q.front().first, x=Q.front().second;
        Q.pop();

        for (int i = 0; i < 4; i++)
        if (!lineout(y+dy[i],x+dx[i]) && t_map[y+dy[i]][x+dx[i]] == 0){
            t_map[y+dy[i]][x+dx[i]] = 2;
            Q.push({y+dy[i],x+dx[i]});
            cnt--;
        }
    }
    return cnt;
}

int Solve(int cnt, int py, int px) {
    //벽뽑기 완료 -> 복사 후 테스트
    if (cnt == 3) {
        for (int i = 0; i < N; i++) for(int j = 0; j < M; j++)
        t_map[i][j]=map[i][j];
        return Test();
    }

    //cnt3까지 벽세우기 후 테스트 -> 최댓값 선별
    int result = 0;
    for (int i = py; i < N; i++) for(int j = 0; j < M; j++)
    if (map[i][j] == 0 && (i>py||(i==py&&j>=px))) {
        map[i][j] = 1;
        result = max(result, Solve(cnt+1,i,j));
        map[i][j] = 0;
    }
    
    return result;
}

int main() {
    Input();
    cout << Solve(0,0,0);
    return 0;
}
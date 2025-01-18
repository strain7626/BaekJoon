#include <stdio.h>
#include <iostream>
#include <queue>

using namespace std;

int H, W, graph[100][100];
bool visited[100][100];
bool keys[26];
bool END;

int dy[] = {-1,1,0,0}, dx[] = {0,0,-1,1};
int result;

void Input() {
    result=0;
    //높이, 너비 입력
    cin >> H >> W;

    //그래프 입력
    for (int i=0;i<H;i++) for (int j=0;j<W;j++) {
        char c;
        cin >> c;
        
        if (c=='.') graph[i][j]=-1;
        else if (c=='*') graph[i][j]=-2;
        else if (c=='$') graph[i][j]=-3;

        //대문자는 넘버로, 소문자는 그냥 저장
        else if (c>='A'&&c<='Z') graph[i][j]=c-'A';
        else graph[i][j]=c;
    }

    //keys 리셋
    for (int i=0;i<26;i++) keys[i]=0;
    //keys 입력
    string S;
    cin >> S;
    if (S=="0") return; else {
        for (char c : S)
            keys[c-'a']=1;
    }
}

bool HaveKey(int y, int x) {
    if (!keys[graph[y][x]]) {
        return false;
    }
    //잠금해제
    else {
        graph[y][x]=-1;
        END=1;
        return true;
    }
}

bool lineOut(int y, int x) {
    if (y<0||y>=H||x<0||x>W) return true;
    return false;
}

void BFS(int _y, int _x) {

    queue<pair<int,int>> myQ;
    myQ.push({_y,_x});
    visited[_y][_x]=1;
    while (!myQ.empty()) {
        int y = myQ.front().first, x = myQ.front().second;
        myQ.pop();
        //문서 먹기
        if (graph[y][x] == -3) {
            result++;
            graph[y][x] = -1;
            END=1;
        }
        //키 먹기
        if (graph[y][x] >= 'a') {
            keys[graph[y][x]-'a'] = 1;
            graph[y][x] = -1;
            END=1;
        }
        //문 안 열리면 돌아가
        if (graph[y][x]>=0 && graph[y][x]<=25) if (!HaveKey(y,x)) continue;

        //주변 칸 탐색
        for (int i = 0; i < 4; i++) {
            int fy = y+dy[i], fx = x+dx[i];
            if (graph[fy][fx] != -2 && !visited[fy][fx] && !lineOut(fy,fx)) {
                myQ.push({fy,fx});
                visited[fy][fx]=1;
            }
        }
    }
}

void Solve() {
    /*
    1. 테두리를 돌면서 입구 찾기
    2. 찾았으면 들어가기
    3. 들어가서 BFS탐색 먹을 수 있는 거 다 먹고 체크하기
    4. 다 돌았으면 나머지 테두리 탐색

    탈출. 돌았을때 변화가 없으면 끝
    */
    END=1;
    while (END) {
        END=0;
        for (int i=0;i<H;i++) for (int j=0;j<W;j++) visited[i][j] = 0;

        //세로 벽 탐색
        for (int i=0;i<H;i++) {
            if ((graph[i][0] != -2) && !visited[i][0]) BFS(i,0);
            if (graph[i][W-1] != -2 && !visited[i][W-1]) BFS(i,W-1);
        }

        //가로 벽 탐색
        for (int j=1;j<W-1;j++) {
            if (graph[0][j] != -2 && !visited[0][j]) BFS(0,j);
            if (graph[H-1][j] != -2 && !visited[H-1][j]) BFS(H-1,j);
        }
    }
    

}

int main() {
    int T;
    cin >> T;
    while (T--) {
        Input();
        Solve();
        cout << result << endl;
    }
}
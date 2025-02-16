#include <iostream>
#include <vector>
using namespace std;

typedef struct _shape {
    int x_size, y_size;
    vector<vector<bool>> body;

    _shape(int _y_size = 0, int _x_size = 0) : y_size(_y_size), x_size(_x_size) {
        body = vector<vector<bool>>(y_size, vector<bool>(x_size, 0));
    }

    void Rotate() {
        vector<vector<bool>> rotated_body(x_size, vector<bool>(y_size));

        // 바뀌는 부분
        for (int y = 0; y < y_size; y++) for (int x = 0; x < x_size; x++)
            rotated_body[x][y_size-1 - y] = body[y][x];

        swap(x_size, y_size);
        body = rotated_body;
    }

} shape;

int     N, M, K,
        R, C;
shape   stickers[100];
bool    graph[40][40];
int     ans;

void Input() {
    cin >> N >> M >> K;

    for (int i=0;i<K;i++) {
        cin >> R >> C;
        stickers[i] = shape(R, C); 
        for (int y = 0; y < R; y++) for (int x = 0; x < C; x++) {
            int t; cin >> t;
            stickers[i].body[y][x] = t;
        }
    }
}

bool Attach(int dy, int dx, shape &sticker) {
    // 위치에 붙이기 가능 여부
    for (int y = 0; y < sticker.y_size; y++) for (int x = 0; x < sticker.x_size; x++)
        if (sticker.body[y][x] && graph[dy+y][dx+x]) return false;    
    
    // 붙이기 + 답 새기
    for (int y = 0; y < sticker.y_size; y++) for (int x = 0; x < sticker.x_size; x++)
        if (sticker.body[y][x]) {
            graph[dy+y][dx+x] = 1;
            ans++;
        }

    return true;
}

bool Find_place(shape &sticker) { 
    // 위치 조정
    for (int dy = 0; dy < N-sticker.y_size+1; dy++) for (int dx = 0; dx < M-sticker.x_size+1; dx++)
        if (Attach(dy, dx, sticker)) return true;

    return false;
}

void Solve() {
    for (int i = 0; i < K; i++) { // 스티커 개수만큼 
        for (int j = 0; j < 4; j++) { // 4번 회전
            if (j != 0) stickers[i].Rotate();
            if (Find_place(stickers[i])) break;
        }
    }
}

int main() {
    Input();
    Solve();
    cout << ans;
}
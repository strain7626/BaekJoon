#include <iostream>
#include <queue>

#define MAX_SIZE 100

using namespace std;

int N, graph[100][100];
vector<pair<int,int>> outline;
vector<int> id;

int dx[] = {-1,1,0,0}, dy[] = {0,0,-1,1};

void Input() {
    cin >> N;
    for (int i = 0; i < N; i++) for (int j = 0; j < N; j++)
        cin >> graph[i][j];
}

bool lineout(int y, int x) {
    if (x<0||x>=N||y<0||y>=N) return true;
    return false;
}

void Assign(int _y, int _x, int num) {
    queue<pair<int,int>> myQ;
    myQ.push({_y,_x});

    while (!myQ.empty()) {
        int x = myQ.front().second, y = myQ.front().first;
        myQ.pop();

        for (int i = 0; i < 4; i++) {
            if (!lineout(y+dy[i],x+dx[i]) && graph[y+dy[i]][x+dx[i]] == 0) {
                outline.push_back({y,x});
                id.push_back(num);
            }
            if (!lineout(y+dy[i],x+dx[i]) && graph[y+dy[i]][x+dx[i]] == 1) {
                graph[y+dy[i]][x+dx[i]] = num;
                myQ.push({y+dy[i],x+dx[i]});
            }
        }
    }
}

void Classify() {
    int num = 2;

    for (int i = 0; i < N; i++) for (int j = 0; j < N; j++)
    if (graph[i][j] == 1) Assign(i,j,num++);

}

int HowFar(pair<int,int> p1, pair<int,int> p2) {
    int x1 = p1.second, y1 = p1.first;
    int x2 = p2.second, y2 = p2.first;

    int fx = x2-x1, fy = y2-y1;
    if (fx < 0) fx *= -1;
    if (fy < 0) fy *= -1;

    return fx+fy;    
}

int Solve() {
    int mini = 1000;
    for (int i = 0; i < outline.size(); i++) for (int j = i+1; j < outline.size(); j++)
        if (id[i] != id[j]) {
            int t = HowFar(outline[i],outline[j]);
            if (t < mini) mini = t;
        }
    return mini-1;
}

int main() {
    Input();
    Classify();
    cout << Solve();

    return 0;
}
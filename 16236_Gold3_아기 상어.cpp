#include <iostream>
#include <queue>
#include <cmath>

using namespace std;

int N;
int graph[20][20];
int x, y;
int S = 2;

void Input() {
    int t;
    cin >> N;
    for (int i = 0; i < N; i++) for (int j = 0; j < N; j++){
        cin >> t;
        if (t==9) {x=j;y=i;graph[i][j]=0;}
        else graph[i][j] = t;
    }
}

int main() {
    Input();
}
#include <iostream>

using namespace std;

int N,M;
int arr[500][500];

int shape[7][3][2] = {
    {{0,1},{0,2},{0,3}},
    {{0,1},{1,0},{1,1}},
    {{1,0},{2,0},{2,1}},
    {{1,0},{1,1},{2,1}},
    {{0,1},{1,1},{0,2}},
    {{0,1},{0,2},{1,2}},
    {{0,1},{1,1},{1,2}},
};
int limit[7][2] = {
    {0,3},
    {1,1},
    {2,1},
    {2,1},
    {1,2},
    {1,2},
    {1,2},
};
int cnt_Rotate[7] = {2,0,4,4,4,4,4};

void Input() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) for (int j = 0; j < M; j++)
    cin >> arr[i][j];
}

int main() {
    Input();

}
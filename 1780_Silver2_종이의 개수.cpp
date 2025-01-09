#include <iostream>
#include <vector>

using namespace std;

int N;
vector<vector<int>> Paper;
int result[3];

void input() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        Paper.push_back(vector<int>(N));
        for (int j = 0; j < N; j++) cin >> Paper[i][j];
    }
}

int solution(vector<vector<int>> paper, int size) {
    if (size == 1) return paper[0][0];
    
    int count[3] = {0,0,0};
    size /= 3;
    vector<vector<int>> next(size, vector<int>(size));

    for (int n = 0; n < 9; n++) {
        int xp = (n%3)*size, yp = (n/3)*size;
        
        for (int y = yp; y < yp + size; y++){
            next[y-yp].assign(paper[y].begin()+xp, paper[y].begin()+xp+size);            
        }

        int t = solution(next, size);
        if (t != -2) count[t+1] += 1;
    }

    for (int i = 0; i < 3; i++) if (count[i] == 9) return i-1;
    for (int i = 0; i < 3; i++) result[i] += count[i];
    return -2;
}

int main() {
    input();
    int t = solution(Paper, N);
    if (t != -2) result[t+1] += 1;
    cout << result[0] << endl << result[1] << endl << result[2];
}
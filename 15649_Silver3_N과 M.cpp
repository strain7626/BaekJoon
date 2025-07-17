#include <iostream>
#include <vector>
using namespace std;

int N, M;

void DFS(vector<int>& V) {
    if (V.size() == M) {
        for (int i : V) cout << i << ' ';
        cout << '\n';
        return;
    }
    for (int i = 1; i <= N; i++) {
        bool flag = 0;
        for (int j : V) if (i == j) flag = 1;
        if (flag) continue;
        V.push_back(i);
        DFS(V);
        V.pop_back();
    }
}

int main() {
    cin >> N >> M;
    vector<int> T;
    DFS(T);
}
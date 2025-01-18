#include <iostream>
#include <queue>
using namespace std;

int main()
{
    priority_queue<int, vector<int>> heap;

    while (true) {
        int N;
        cin >> N;

        if (!N) break;
        heap.push(N);

        cout << heap.size();
    }
}
#include <iostream>
#include <deque>

using namespace std;

#define MAX_SIZE 100000+1

int N, K;
deque<int> myQ;
int visited[MAX_SIZE];

int main() {
    cin >> N >> K;
    myQ.push_back(N);
    visited[N] = 1;
    int cur;
    while (!myQ.empty()) {
        cur = myQ.front();
        myQ.pop_front();

        if (cur == K) {
            cout << visited[cur]-1;
            return 0;
        }

        if (cur*2 < MAX_SIZE && !visited[cur*2]) {
            visited[cur*2] = visited[cur];
            myQ.push_front(cur*2);
        }
        if (cur-1 >= 0 && !visited[cur-1]) {
            visited[cur-1] = visited[cur]+1;
            myQ.push_back(cur-1);
        }
        if (cur+1 < MAX_SIZE && !visited[cur+1]) {
            visited[cur+1] = visited[cur]+1;
            myQ.push_back(cur+1);
        }
    }
    return 0;
}

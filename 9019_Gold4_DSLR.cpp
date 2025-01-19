#include <iostream>
#include <queue>
#define endl "\n"

using namespace std;
string visited[10000];
int A, B;

void Solve() {
    queue<int> myQ;
    myQ.push(A);

    while (!myQ.empty()) {
        int a = myQ.front();
        myQ.pop();
        
        //탈출
        if (a==B) {
            cout << visited[a] << endl;
        }

        //DSLR 연산
        int t = (a*2)%10000;
        if (visited[t].empty() && t!=a) {
            visited[t] = visited[a]+'D';
            myQ.push(a*2%10000);
        }
        t = (a+9999)%10000;
        if (visited[t].empty() && t!=a) {
            visited[t] = visited[a]+'S';
            myQ.push(t);
        }
        t = 10*(a%1000)+(a/1000);
        if (visited[t].empty() && t!=a) {
            visited[t] = visited[a]+'L';
            myQ.push(t);
        }
        t = 1000*(a%10)+(a/10);
        if (visited[t].empty() && t!=a) {
            visited[t] = visited[a]+'R';
            myQ.push(t);
        }
        
    }

}

int main() {
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        cin >> A >> B;
        for (int i=0;i<10000;i++) visited[i].clear();
        
        Solve();
    }
}
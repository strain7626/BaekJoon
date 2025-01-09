#include <iostream>
#include <queue>

using namespace std;

int N, K;
int A[9][9];
int others[2][20];
int cntO[2];

int wins[3];
bool hand[9];

void Input() {
    cin >> N >> K;
    for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) cin >> A[i][j];
    for (int i = 0; i < 20; i++) cin >> others[0][i];
    for (int i = 0; i < 20; i++) cin >> others[1][i];
}

bool DFS(int p1, int p2) {
    cout << p1 <<"vs"<<p2<<endl;
    cout << "승수 : " << wins[0] << wins[1] << wins[2];
    cout << endl;
    if (wins[0] == K) {cout << "내가이김";return true;}
    else if (wins[1] == K || wins[2] == K) {cout << "쟤가이김";return false;}

    //내가 참여
    if (p1 == 0) {
        for (int i = 0; i < N; i++) {
            if (!hand[i]) {
                hand[i] = true;
                if (A[i][others[p2-1][cntO[p2-1]++]-1] == 2) {
                    wins[0]++;
                    if (DFS(0, 3-p2)) return true;
                    cout << endl << "뺀다뺀다" << endl;
                    wins[0]--;
                }
                else {
                    wins[p2]++;
                    if (DFS(1,2)) return true;
                    wins[p2]--;
                }
                cntO[p2]--;
                hand[i] = false;
            }     
        }
    }       
    //내가 안 참여
    else {
        if (A[others[0][cntO[0]++]-1][others[1][cntO[1]++]-1] == 2) {
            wins[1]++;
            if (DFS(0,1)) return true;
            wins[1]--;
        }
        else {
            wins[2]++;
            if (DFS(0,2)) return true;
            cout <<"herehere";
            wins[2]--;
        }
        cntO[0]--;cntO[1]--;
        
    }
    cout << p1 <<"vs"<<p2<<"끝"<<endl<<endl;
    return false;
}

int main() {
    cout << hand[0];
    Input();
    cout << DFS(0, 1);
    return 0;
}
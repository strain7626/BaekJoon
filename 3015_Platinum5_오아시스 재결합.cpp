#include <iostream> 
#include <stack>
using namespace std;

typedef struct _pressedPeople {
    int height;
    int cnt;
    _pressedPeople(int _height, int _cnt) : height(_height), cnt(_cnt) {};
} PPP;

int main() {
    long long result = 0;
    int N; cin >> N;
    
    stack<PPP> S;

    for (int i=0;i<N;i++) {
        int x; cin >> x;
        
        if (S.empty()) {
            S.push({x,1});
            continue;
        }

        while(!S.empty()) {
            if (S.top().height < x) {
                result += S.top().cnt;
                S.pop();
            } else if (S.top().height == x){
                PPP temp = S.top();
                S.pop();

                result += temp.cnt;
                if (!S.empty()) result++;

                S.push(temp);
                break;
            } else {
                result++;
                break;
            }
        }

        if (!S.empty() && S.top().height == x) {
            S.top().cnt++;
        } else {
            S.push({x,1});
        }
    }

    cout << result;
}
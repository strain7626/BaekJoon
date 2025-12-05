#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

map<string,int> s2i;
pair<pair<int,int>,tuple<float,float,float>> rst[6];
int score[4];
float ans[4];

void Calculate(float& P) {
    int _score[4];
    for (int i = 0; i < 4; i++) _score[i] = score[i];

    int M = 0;
    vector<int> win;
    for (int i = 0; i < 4; i++) {
        if (M < _score[i]) { M = _score[i]; win.clear(); win.push_back(i); } 
        else if (M == _score[i]) win.push_back(i);
    }
    
    for (int i = 0; i < win.size(); i++) {
        ans[win[i]] += P/win.size();
        _score[win[i]] = -1; 
    }

    if (win.size() != 1) return; 
    
    M = 0; win.clear();
    for (int i = 0; i < 4; i++) {
        if (M < _score[i]) { M = _score[i]; win.clear(); win.push_back(i); } 
        else if (M == _score[i]) win.push_back(i);
    }

    for (int i = 0; i < win.size(); i++)
        ans[win[i]] += P/win.size();
}

void DFS(int cnt, float P) {
    if (P == 0) {return;}
    if (cnt == 6) {
        Calculate(P);
        return;
    }

    int A = rst[cnt].first.first, B = rst[cnt].first.second;
    float W, D, L; tie(W, D, L) = rst[cnt].second;

    score[A]+=3;
    DFS(cnt+1, P*W);
    score[A]-=3;

    score[A]+=1;
    score[B]+=1;
    DFS(cnt+1, P*D);
    score[A]-=1;
    score[B]-=1;

    score[B]+=3;
    DFS(cnt+1, P*L);
    score[B]-=3;
}

int main() {
    cout.precision(10); cout << fixed;

    for (int i = 0; i < 4; i++) {
        string S; cin >> S;
        s2i[S] = i;
    }
    
    for (int i = 0; i < 6; i++) {
        string A, B; float W, D, L;
        cin >> A >> B >> W >> D >> L;
        rst[i] = {{s2i[A], s2i[B]}, {W, D, L}}; 
    }

    DFS(0, 1);

    for (float& f : ans) cout << f << '\n';
}
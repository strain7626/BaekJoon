#include <bits/stdc++.h>
using namespace std;

int M, N;
priority_queue<int,vector<int>,less<>> pre; 
priority_queue<int,vector<int>,greater<>> post;

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    int T; cin >> T;
    while (T--) {
        cin >> M; 
        cout << M/2+1;
        
        while (!pre.empty()) pre.pop();
        while (!post.empty()) post.pop();

        for (int i = 0; i < M; i++) {
            cin >> N;
            if (i == 0 || N >= post.top()) post.push(N);
            else pre.push(N);

            if (i%2 == 0) {
                if (pre.size()-1 == post.size()) {int t = pre.top(); pre.pop(); post.push(t);}
                else if (pre.size() == post.size()-3) {int t = post.top(); post.pop(); pre.push(t);}

                if (i%20 == 0) cout << '\n';
                cout << post.top() << ' ';
            }
        }

        cout << '\n';
    }
}
#include <bits/stdc++.h>

using namespace std;

int N,M;
char A[9][9];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    cin >> N >> M;
    
    for (int i=0;i<N;i++) for (int j=0;j<M;j++) cin >> A[i][j];
    
    int ans=-1;
    for (int si=0;si<N;si++) for (int sj=0;sj<M;sj++) {
        for (int di=-N;di<N;di++) for (int dj=-M;dj<M;dj++) {
            if (!di&&!dj) continue;
            string s;
            for (int i=si,j=sj;0<=i&&i<N&&0<=j&&j<M;i+=di,j+=dj) {
                s+=A[i][j];

                int a=stoi(s),b=0;
                while (b*b<a) b++;
                if (b*b==a) ans=max(ans,a); 
            }

        }
    }
    cout << ans;
}
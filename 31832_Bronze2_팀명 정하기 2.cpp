#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    string S;
    int T;cin>>T;while(T--){
        cin>>S;
        int a=0,A=0,n=0;
        for(char c:S) if('a'<=c&&c<='z')a++;else if('A'<=c&&c<='Z')A++;else if('0'<=c&&c<='9')n++;
        if(a>=A&&n!=S.size()&&S.size()<=10) break;
    }
    cout<<S;
}
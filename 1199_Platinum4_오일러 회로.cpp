#include <iostream>
#include <vector>
using namespace std;
int n;
vector<int> degree;
vector<vector<int>> adj;
vector<int> route;
int edgeNum=0;

void getEuler(int here){
    for (int there=1; there<=n; there++){
        while(adj[here][there] > 0){
            adj[here][there]--;//간선 줄이기
            adj[there][here]--;
            edgeNum--;
            getEuler(there);
        }
    }
    route.push_back(here); //dfs방식
}

int main(){
    cin>>n;
    adj = vector<vector<int>>(n+1, vector<int>(n+1));
    degree = vector<int>(n+1, 0);
    
    for (int i=1; i<=n; i++){
        for (int j=1; j<=n; j++){
            cin>>adj[i][j];
        }
    }
    // 노드 당 선 개수, 그냥 전체 선 개수 계산
    for (int i=1; i<=n; i++){
        for (int j=i+1; j<=n; j++){
            if (adj[i][j] > 0){
                degree[i] += adj[i][j];
                degree[j] += adj[i][j];
                edgeNum += adj[i][j];
            }
        }
    }
    
    bool oddCount=false; // 차수가 홀수인 노드 유무
    for (int i=1; i<=n; i++){
        if (degree[i]%2==1){
            oddCount=true;
            break;
        }
    }
    if (oddCount) cout<<"-1";
    else{
        getEuler(1); // 뭐든 상관 X
        if (edgeNum != 0) cout<<"-1"; // 0아니면 오일러 회로 성립 X
        else{
            for (int i=0; i<route.size(); i++){
                cout<<route[i]<<' ';
            }
        }
    }
}
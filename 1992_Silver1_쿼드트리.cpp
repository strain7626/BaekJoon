#include <iostream>
#include <vector>

using namespace std;

string solution(vector<string> V, int size) {
    if (size == 1) return V[0];

    string result;
    size /= 2;
    vector<pair<int, int>> range = {{0,0},{0,size},{size,0},{size,size}};

    for (int i = 0; i < 4; i++) {
        vector<string> next;
        
        for (int delta = 0; delta < size; delta++) 
            next.push_back(V[range[i].first + delta].substr(range[i].second, size));

        result.append(solution(next, size));
    }

    if (result == "0000") return "0";
    if (result == "1111") return "1";
    return "("+result+")";
}

int main(){
    int N;
    vector<string> input;

    cin >> N;

    for (int i = 0; i < N; i++) {
        string temp;
        cin >> temp;
        input.push_back(temp);
    }

    cout << solution(input, N);
}
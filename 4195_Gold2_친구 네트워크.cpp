#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

int F;
vector<int> uni;
vector<int> uni_size;
map<string,int> name_num; // 이름을 정수로 변환할때 사용

int getNum(string name) { // 문자열 형태로 들어온 입력을 정수 형태로 반환해준다. map 안에 없던 이름일때 새롭게 추가해준다.
    if (name_num[name]) return name_num[name];
    int new_num = uni.size();
    uni.push_back(new_num);
    uni_size.push_back(1);
    return name_num[name] = new_num;
}

int uni_find(int num) {
    if (uni[num] == num) return num;
    return uni[num] = uni_find(uni[num]);
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    int T; cin >> T;
    while (T--) {
        uni = {0}; 
        uni_size = {0};
        name_num.clear();

        cin >> F;
        for (int i = 0; i < F; i++) {
            string s1, s2; cin >> s1 >> s2;
            int n1 = uni_find(getNum(s1)), n2 = uni_find(getNum(s2));

            if (n1 != n2) {
                uni[n1] = n2;
                uni_size[n2] += uni_size[n1];
            }

            cout << uni_size[n2] << endl;
        }
    }
}
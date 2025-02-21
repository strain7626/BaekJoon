    #include <iostream>
    using namespace std;

    int main() {
        while (true) {
            string ans = "yes";
            string A; cin >> A;
            if (A == "0") break;
            int l = 0, r = A.size()-1;
            while (l < r) {
                if (A[l] != A[r]) {ans =  "no";break;}
                l++;r--;
            }
            cout << ans << endl;
        }
    }
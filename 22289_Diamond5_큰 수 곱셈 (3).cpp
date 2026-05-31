#include <bits/stdc++.h>

using namespace std;
using cpx=complex<double>;

const double PII=acos(-1);

void fft(vector<cpx> &vec,bool inv) {
    int len=vec.size();
    for(int i=1,j=0;i<len;i++) {
        int bit=len>>1;
        while(j>=bit) j-=bit,bit>>=1;
        j+=bit;
        if(i<j) swap(vec[i],vec[j]);
    }
    for(int k=1;k<len;k<<=1) {
        double ang=(inv?-PII/k:PII/k);
        cpx dir(cos(ang),sin(ang));
        for(int i=0;i<len;i+=k*2) {
            cpx w(1,0);
            for(int j=0;j<k;j++) {
                cpx cur=vec[i+j+k]*w;
                vec[i+j+k]=vec[i+j]-cur;
                vec[i+j]+=cur;
                w*=dir;
            }
        }
    }
    if(inv) for(int i=0;i<len;i++) vec[i]/=len;
}

vector<int> mul(string st1,string st2) {
    vector<cpx> v_a(st1.size()),v_b(st2.size());
    for(int i=0;i<st1.size();i++) v_a[i]=cpx(st1[st1.size()-1-i]-'0',0);
    for(int i=0;i<st2.size();i++) v_b[i]=cpx(st2[st2.size()-1-i]-'0',0);
    
    int len=2;
    while(len<v_a.size()+v_b.size()) len<<=1;
    v_a.resize(len);v_b.resize(len);
    
    fft(v_a,0);fft(v_b,0);
    for(int i=0;i<len;i++) v_a[i]*=v_b[i];
    fft(v_a,1);
    
    vector<int> res(len);
    for(int i=0;i<len;i++) {
        res[i]+=(int)round(v_a[i].real());
        if(res[i]>=10) {
            if(i+1==len) res.push_back(res[i]/10);
            else res[i+1]+=res[i]/10;
            res[i]%=10;
        }
    }
    while(res.size()>1&&res.back()==0) res.pop_back();
    return res;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    string A,B;cin>>A>>B;
    if(A=="0"||B=="0") {cout<<0<<'\n';return 0;}
    
    vector<int> ans=mul(A,B);
    for(int i=ans.size()-1;i>=0;i--) cout<<ans[i];
    cout<<'\n';
}
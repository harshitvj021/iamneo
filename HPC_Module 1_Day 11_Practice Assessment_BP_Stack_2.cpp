#include<bits/stdc++.h>
using namespace std;
int checker(string s,int n) {
    stack<char> st;
    st.push(s[n]);
    for(int i=n+1;i<s.size();i++) {
        if(st.top()=='[' && s[i]==']') {
            st.pop();
            if(st.empty()) {
                return i;
            }
        }
        else if(s[i]=='[') {
            st.push(s[i]);
        }
    }
    return -1;
}

int main() {
    string s;
    cin >>s;
    int n;
    cin >>n;
    int ans = checker(s,n);
    cout << ans << endl;
    return 0;
}
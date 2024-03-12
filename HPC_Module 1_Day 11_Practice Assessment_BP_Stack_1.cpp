#include<bits/stdc++.h>
using namespace std;
void checker(string s) {
    stack<char> st;
    for(int i=0;i<s.size();i++) {
        if(st.empty()) {
            st.push(s[i]);
        }
        else if((st.top()=='(' && s[i]==')')||(st.top()=='{' && s[i]=='}') || (st.top()=='[' && s[i]==']')) {
            st.pop();
        }
        else {
            st.push(s[i]);
        }
    }
    if(st.empty()) {
        cout << "Balanced" << endl;
    }
    else {
        cout << "Not Balanced" << endl;
    }
}

int main() {
    string s;
    cin>>s;
    checker(s);
    return 0;
}
#include <iostream>
#include <stack> 
#include <vector>

using namespace std;

int getInfix(string s) {
    stack<int>st;
    for(int i=0;i<s.size();i++)  {
        if(isdigit(s[i])) {
            st.push(s[i]-'0');
        }
        
        else {
            int a1=st.top();
            st.pop();
            int a2 = st.top();
            st.pop();
            switch(s[i]) {
                case '+':
                st.push(a2+a1);
                break;
                case '-':
                st.push(a2-a1);
                break;
                case '*':
                st.push(a2*a1);
                break;
                case '/':
                st.push(a2/a1);
                break;
            }
        }
    }
    return st.top();
}

int main() {
    int size;
    cin >> size;
    int size1 =size;
    vector<string> v;
    while (size--) {
        string s;
        cin>>s;
        v.push_back(s);
    }
    int i=0;
    while(i<size1) {
        cout << getInfix(v[i]) << endl;
        i++;
    }
    return 0;
}

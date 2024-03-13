#include <bits/stdc++.h>
using namespace std;
bool bracket(char x) {
    if(x=='(' || x==')' || x=='{' || x=='}' || x=='[' || x==']') {
        return true;
    }
    else {
        return false;
    }
}
bool stringChecker(string s) {
    int size = s.size();
    stack<char> temp;
    for(int i=0;i<size;i++) {
        if(temp.empty()) {
            if(bracket(s[i])) {
                temp.push(s[i]);
            }
        }
        else if((temp.top()=='(' && s[i]==')') || (temp.top() =='{' && s[i]=='}') || (temp.top()=='[' && s[i]==']')) {
            temp.pop();
        }
        else {
            if(bracket(s[i]))
            temp.push(s[i]);
        }
    }
    if(temp.empty()) {
        return true;
    }
    return false;
}

int main() {
    string s;
    cin >>s;
    bool ans= stringChecker(s);
    if(ans) {
        cout << "The parentheses are balanced" << endl;
    }
    else {
        cout << "The parentheses are not balanced" << endl;
    }
    return 0;
}
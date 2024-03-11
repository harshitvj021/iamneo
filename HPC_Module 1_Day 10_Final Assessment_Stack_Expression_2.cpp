#include <iostream>
#include <stack>

using namespace std;

bool isOperand(char x) {
    if((x>='a' && x<= 'z') || (x>='A' && x<='Z')) {
        return true;
    }
    return false;
}

string getInfix(string exp) {
    stack<string> s;
    for(int i=0;exp[i]!='\0';i++) {
        if(isOperand(exp[i])) {
            string op(1,exp[i]) ;
            s.push(op);
    }
    else {
        string a1 = s.top();
        s.pop();
        string a2 = s.top();
        s.pop();
        s.push("("+ a2 + exp[i] + a1 + ")");
    }
}
return s.top();
}

int main() {
    string exp;
    cin>>exp;
    cout << getInfix(exp) << endl;
    return 0;
}
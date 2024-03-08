// You are using GCC
#include <iostream>
#include <string>
#include <cctype>

using namespace std;

struct Stack {
    int top;
    int capacity;
    int* array;
    
    Stack(int capacity) {
        this->capacity = capacity;
        top =-1;
        array = new int [capacity];
    }
    
    ~Stack() {
        delete[] array;
    }
    
    bool isEmpty() {
        return top == -1;
    }
    
    int peek() {
        return array[top];
    }
    
    int pop() {
        if (!isEmpty()) {
            return array[top--];
        }
        return '$';
    }
    
    void push(int value) {
        array[++top] = value;
    }
};

int evaluatePostfix(string exp) {
    Stack Stack(exp.length());
    
    for (int i =0; i<exp.length(); i++) {
        if (exp[i] == ' ') {
            continue;
        } else if (isdigit(exp[i])) {
            int num =0;
            while (i < exp.length() && isdigit(exp[i])) {
                num = num * 10 + (exp[i] - '0');
                i++;
            } 
            i--;
            Stack.push(num);
        } else {
            int val1 = Stack.pop();
            int val2 = Stack.pop();
            switch (exp[i]) {
                case '+':
                Stack.push(val2 + val1);
                break;
                case '-':
                Stack.push(val2 - val1);
                break;
                case '*':
                Stack.push(val2*val1);
                break;
                case '/':
                Stack.push(val2/val1);
                break;
            }
        }
    }
    return Stack.pop();
}

int main() {
    string exp;
    getline(cin,exp);
    cout << evaluatePostfix(exp) << endl;
    return 0;
}
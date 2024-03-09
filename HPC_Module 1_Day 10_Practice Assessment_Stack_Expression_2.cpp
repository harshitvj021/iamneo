// You are using GCC
#include <iostream>
#include <stack>
#include <sstream>
#include <iomanip>

using namespace std;
float calculateTotalCost(float  room_rent, float procedure_cost, float medication_cost) {
    return room_rent + procedure_cost +medication_cost;
}

float evaluatePostfixExpression(const string& expression) {
    stack<float> operands;
    stringstream ss(expression);
    string token;
    
    while (ss >> token) {
        if (isdigit(token[0])) {
            operands.push(stof(token));
        } else {
            float operand2 = operands.top();
            operands.pop();
            float operand1 = operands.top();
            switch (token[0]) {
                case '+':
                
                operands.push(operand1 + operand2);
                break;
                case '-':
                operands.push(operand1 - operand2);
                break;
                case '*':
                operands.push(operand1 * operand2);
                break;
                case '/':
                operands.push(operand1 / operand2);
                break;
            }
        }
    }
    return operands.top();
}

int main() {
    float room_rent, procedure_cost, medication_cost;
    cin >> room_rent >> procedure_cost >> medication_cost;
    
    float total_cost = calculateTotalCost(room_rent,procedure_cost, medication_cost);
    cout << fixed << setprecision(2) << total_cost << endl;
    
    return 0;
}
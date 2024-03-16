#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class DinnerPlates {
private:
    vector<stack<int>> stacks;
    int capacity;

public:
    DinnerPlates(int capacity) {
        this->capacity = capacity;
    }

    void push(int val) {
        stack<int>* leftmostStack = getLeftmostStackWithSpace();
        leftmostStack->push(val);
    }

    int pop() {
        while (!stacks.empty() && stacks.back().empty()) {
            stacks.pop_back();
        }
        if (stacks.empty()) {
            return -1;
        }
        int value = stacks.back().top();
        stacks.back().pop();
        return value;
    }

    int popAtStack(int index) {
        if (index >= stacks.size()) {
            return -1;
        }
        stack<int>& stackAtIndex = stacks[index];
        if (stackAtIndex.empty()) {
            return -1;
        }
        int value = stackAtIndex.top();
        stackAtIndex.pop();
        return value;
    }

private:
    stack<int>* getLeftmostStackWithSpace() {
        for (stack<int>& stack : stacks) {
            if (stack.size() < capacity) {
                return &stack;
            }
        }
        stacks.emplace_back();
        return &stacks.back();
    }
};

int main() {
    int capacity;
    cin >> capacity;

    DinnerPlates dinnerPlates(capacity);

    while (true) {
        int choice;
        cin >> choice;

        if (choice == 1) {
            int value;
            cin >> value;
            dinnerPlates.push(value);
            cout << value << endl;
        } else if (choice == 2) {
            int value = dinnerPlates.pop();
            cout << value << endl;
        } else if (choice == 3) {
            int index, value;
            cin >> index;
            value = dinnerPlates.popAtStack(index);
            cout << index << ":" << value << endl;
        } else if (choice == 4) {
            break;
        } else {
            cout << "Invalid choice" << endl;
        }
    }

    return 0;
}

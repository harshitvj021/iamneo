#include <iostream>
using namespace std;

struct Node {
    int coefficient;
    int exponent;
    Node* next;

    Node(int coef, int exp) : coefficient(coef), exponent(exp), next(nullptr) {}
};

struct Polynomial {
    Node* head;

    Polynomial() : head(nullptr) {}

    void addTerm(int coef, int exp) {
        Node* newNode = new Node(coef, exp);

        if (head == nullptr) {
            head = newNode;
        } else {
            Node* ptr = head;
            while (ptr->next != nullptr) {
                ptr = ptr->next;
            }
            ptr->next = newNode;
        }
    }

    void displayPolynomial() {
        if (head == nullptr) {
            cout << "0";
            return;
        }
        Node* current = head;
        while (current != nullptr) {
            cout << current->coefficient << "x^" << current->exponent;
            if (current->next != nullptr) {
                cout << " + ";
            }
            current = current->next;
        }
    }

    Polynomial simplifyPolynomial() {
        if (head == nullptr || head->next == nullptr) {
            return *this;
        }
        Node* ptr1 = head, * ptr2, * prev = nullptr;
        while (ptr1 != nullptr) {
            ptr2 = ptr1->next;
            prev = ptr1;
            while (ptr2 != nullptr) {
                if (ptr1->exponent == ptr2->exponent) {
                    ptr1->coefficient += ptr2->coefficient;
                    prev->next = ptr2->next;
                    delete ptr2;
                    ptr2 = prev->next;
                } else {
                    prev = ptr2;
                    ptr2 = ptr2->next;
                }
            }
            ptr1 = ptr1->next;
        }
        return *this;
    }
};

int main() {
    Polynomial polynomial;
    int terms;
    cin >> terms;

    for (int i = 0; i < terms; i++) {
        int coefficient, exponent;
        cin >> coefficient >> exponent;
        polynomial.addTerm(coefficient, exponent);
    }

    cout << "Original polynomial: ";
    polynomial.displayPolynomial();

    cout << "\nSimplified polynomial: ";
    polynomial.simplifyPolynomial().displayPolynomial();

    return 0;
}
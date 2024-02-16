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

    void insertTerm(int coef, int exp) {
        Node* newNode = new Node(coef, exp);

        if (head == nullptr) {
            head = newNode;
        } else {
            Node* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    void multiply(Polynomial& polynomial2) {
        if (head == nullptr || polynomial2.head == nullptr) {
            cout << "Empty polynomial(s)!" << endl;
            return;
        }

        Polynomial result;
        Node* current1 = head;

        while (current1 != nullptr) {
            Node* current2 = polynomial2.head;
            while (current2 != nullptr) {
                int coef = current1->coefficient * current2->coefficient;
                int exp = current1->exponent + current2->exponent;
                result.insertTerm(coef, exp);
                current2 = current2->next;
            }
            current1 = current1->next;
        }

        display(result);
    }

    void display(Polynomial& polynomial) {
        if (polynomial.head == nullptr) {
            cout << "Empty polynomial!" << endl;
            return;
        }

        Node* current = polynomial.head;
        while (current != nullptr) {
            cout << current->coefficient << "x^" << current->exponent;
            if (current->next != nullptr) {
                cout << " + ";
            }
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    Polynomial polynomial1;
    int n1;
    cin >> n1;

    for (int i = 0; i < n1; i++) {
        int coef, exp;
        cin >> coef >> exp;
        polynomial1.insertTerm(coef, exp);
    }

    Polynomial polynomial2;
    int n2;
    cin >> n2;

    for (int i = 0; i < n2; i++) {
        int coef, exp;
        cin >> coef >> exp;
        polynomial2.insertTerm(coef, exp);
    }

    cout << "Polynomial 1: " << endl;
    polynomial1.display(polynomial1);
    cout << "Polynomial 2: " << endl;
    polynomial2.display(polynomial2);

    cout << "Result of polynomial multiplication: " << endl;
    polynomial1.multiply(polynomial2);

    return 0;
}

#include <iostream>
#include <cmath>
using namespace std;

struct PolyTerm {
    int coeff;
    int exp;
    PolyTerm* next;

    PolyTerm(int c, int e) : coeff(c), exp(e), next(nullptr) {}
};

PolyTerm* createTerm(int coeff, int exp) {
    return new PolyTerm(coeff, exp);
}

void addTerm(PolyTerm*& poly, int coeff, int exp) {
    PolyTerm* term = createTerm(coeff, exp);
    if (poly == nullptr) {
        poly = term;
        return;
    }
    PolyTerm* last = poly;
    while (last->next != nullptr) {
        last = last->next;
    }
    last->next = term;
}

int evaluatePoly(PolyTerm* poly, int x) {
    int result = 0;
    while (poly != nullptr) {
        result += poly->coeff * pow(x, poly->exp);
        poly = poly->next;
    }
    return result;
}

int main() {
    int degree, coeff, exp, x;
    PolyTerm* poly = nullptr;
    cin >> degree;

    for (int i = degree; i >= 0; i--) {
        cin >> coeff;
        if (coeff != 0) {
            addTerm(poly, coeff, i);
        }
    }
    cin >> x;
    int result = evaluatePoly(poly, x);
    cout << result << endl;

    // Clean up memory
    while (poly != nullptr) {
        PolyTerm* temp = poly->next;
        delete poly;
        poly = temp;
    }

    return 0;
}

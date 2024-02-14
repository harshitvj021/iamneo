#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};

// Custom linked list class
class LinkedList {
public:
    Node* head;

    LinkedList() : head(nullptr) {}

    // Function to insert a node at the end of the linked list
    void insert(int val) {
        Node* newNode = new Node(val);
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

    // Function to display the linked list
    void display() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
    }

    // Function to check if the linked list is empty
    bool isEmpty() {
        return head == nullptr;
    }
};

bool checkSum(int sumLeft[], int k) {
    for (int i = 0; i < k; i++) {
        if (sumLeft[i] != 0) {
            return false;
        }
    }
    return true;
}

bool subsetSum(int S[], int n, int sumLeft[], int A[], int k) {
    if (checkSum(sumLeft, k)) {
        return true;
    }

    if (n < 0) {
        return false;
    }

    bool result = false;

    for (int i = 0; i < k; i++) {
        if (!result && (sumLeft[i] - S[n]) >= 0) {
            A[n] = i + 1;
            sumLeft[i] -= S[n];
            result = subsetSum(S, n - 1, sumLeft, A, k);
            sumLeft[i] += S[n];
        }
    }

    return result;
}

// Function for solving k–partition problem.
void partition(LinkedList& list, int k) {
    Node* current = list.head;
    int n = 0;
    int sum = 0;

    // Calculate the sum and count of elements
    while (current != nullptr) {
        sum += current->data;
        current = current->next;
        n++;
    }

    if (n < k || sum % k != 0) {
        cout << "k-partition of set S is not possible" << endl;
        return;
    }

    int S[n], A[n], sumLeft[k];
    current = list.head;

    // Copy elements to array S
    for (int i = 0; i < n; i++) {
        S[i] = current->data;
        current = current->next;
    }

    // Initialize sumLeft array
    for (int i = 0; i < k; i++) {
        sumLeft[i] = sum / k;
    }

    if (!subsetSum(S, n - 1, sumLeft, A, k)) {
        cout << "k-partition of set S is not possible" << endl;
        return;
    }

    for (int i = 0; i < k; i++) {
        cout << "Partition " << i << " is ";
        for (int j = 0; j < n; j++) {
            if (A[j] == i + 1) {
                cout << S[j] << " ";
            }
        }
        cout << endl;
    }
}

int main() {
    int n, k;
    cin >> n;
    LinkedList list;

    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        list.insert(val);
    }

    cin >> k;
    partition(list, k);
    return 0;
}
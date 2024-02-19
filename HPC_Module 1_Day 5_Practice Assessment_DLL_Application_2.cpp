// You are using GCC
#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode *prev;
    ListNode(int x) : val(x), next(NULL), prev(NULL) {}
};

ListNode* createDoublyLinkedList(vector<int>& elements) {
    if (elements.empty())
    return nullptr;
    
    ListNode* head =new ListNode(elements[0]);
    ListNode* prevNode = head;
    
    for(int i=1; i<elements.size(); ++i) {
        ListNode* newNode = new ListNode(elements[i]);
        prevNode->next = newNode;
        newNode ->prev = prevNode;
        prevNode = newNode;
    }
    
    return head;
}

void displayDoublyLinkedList(ListNode* head) {
    ListNode* current = head;
    while (current) {
        cout << current->val;
        if (current->next) {
            cout << " ";
        }
        current = current->next;
    }
}

int main() {
    int N;
    cin >> N;
    vector<int> elements(N);
    for (int i=0;i<N;++i) {
        cin >> elements[i];
    }
    
    ListNode* head = createDoublyLinkedList(elements);
    
    displayDoublyLinkedList(head);
    cout << endl;
    
    ListNode* current = head;
    while (current) {
        ListNode*nextNode = current->next;
        delete current;
        current = nextNode;
    }
    
    return 0;
}
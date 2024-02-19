// You are using GCC
#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode *prev;
    ListNode(int x) : val(x), next(NULL) , prev(NULL) {}
};

bool isPalindrome(ListNode* head) {
    if (!head || !head->next)
    return true;
    
    ListNode *slow = head, *fast = head;
    while (fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    
    ListNode *prev =nullptr;
    ListNode *curr = slow->next;
    while (curr) {
        ListNode *nextTemp = curr->next;
        curr->next = prev;
        curr->prev = nextTemp;
        prev = curr;
        curr = nextTemp;
    }
    slow->next = prev;
    
    ListNode *p1=head, *p2 = slow->next;
    while (p1 && p2) {
        if (p1->val != p2->val)
        return false;
        p1 = p1->next;
        p2 = p2->next;
    }
    
    return true;
}

int main() {
    int N;
    cin >> N;
    vector<int> elements(N);
    for (int i=0;i<N; ++i) {
        cin >> elements[i];
    }
    
    ListNode *head = nullptr;
    ListNode *prevNode =nullptr;
    for (int i=0;i<N;++i) {
        ListNode *newNode = new ListNode(elements[i]);
        if(prevNode) {
            prevNode->next = newNode;
            newNode->prev = prevNode;
        } else {
            head = newNode;
        }
        prevNode =newNode;
    }
    
    bool isPal = isPalindrome(head);
    if (isPal) {
        cout << "The doubly linked list is a palindrome." << endl;
    } else {
        cout << "The doubly linked list is not a palindrome." << endl; 
    }
    
    ListNode *current =head;
    while (current) {
        ListNode *nextNode = current->next;
        delete current;
        current =nextNode;
    }
    return 0;
}
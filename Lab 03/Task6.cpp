#include <iostream>
using namespace std;

class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
    Node(int v) : val(v), prev(nullptr), next(nullptr), child(nullptr) {}
};

class Solution {
public:
    Node* flatten(Node* head) {
        Node* curr = head;
        while (curr) {
            if (curr->child) {
                Node* childHead = curr->child;
                Node* childTail = childHead;
                while (childTail->next) {
                    childTail = childTail->next;
                }
                if (curr->next) {
                    childTail->next = curr->next;
                    curr->next->prev = childTail;
                }
                curr->next = childHead;
                childHead->prev = curr;
                curr->child = nullptr;
            }
            curr = curr->next;
        }
        return head;
    }
};

void printList(Node* head) {
    Node* it = head;
    while (it) {
        cout << it->val << " ";
        it = it->next;
    }
    cout << endl;
}

int main() {
    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    Node* n4 = new Node(4);
    Node* n5 = new Node(5);

    n1->next = n2; n2->prev = n1;
    n2->next = n3; n3->prev = n2;
    n2->child = n4;
    n4->next = n5; n5->prev = n4;

    Solution sol;
    Node* head = sol.flatten(n1);

    printList(head);

    return 0;
}
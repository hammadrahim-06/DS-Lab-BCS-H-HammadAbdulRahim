#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

struct DoublyListNode {
    int val;
    DoublyListNode* prev;
    DoublyListNode* next;
    DoublyListNode(int x) : val(x), prev(nullptr), next(nullptr) {}
};

class Solution {
public:
    DoublyListNode* convertToDoubly(ListNode* head) {
        if (!head) return nullptr;
        DoublyListNode* dHead = new DoublyListNode(head->val);
        DoublyListNode* dIt = dHead;
        for (ListNode* it = head->next; it; it = it->next) {
            dIt->next = new DoublyListNode(it->val);
            dIt->next->prev = dIt;
            dIt = dIt->next;
        }
        return dHead;
    }

    ListNode* convertToCircular(ListNode* head) {
        if (!head) return nullptr;
        ListNode* it = head;
        while (it->next) it = it->next;
        it->next = head;
        return head;
    }
};

ListNode* buildSinglyList(const vector<int>& vals) {
    if (vals.empty()) return nullptr;
    ListNode* head = new ListNode(vals[0]);
    ListNode* it = head;
    for (int i = 1; i < (int)vals.size(); i++) {
        it->next = new ListNode(vals[i]);
        it = it->next;
    }
    return head;
}

void printDoublyList(DoublyListNode* head) {
    cout << "Doubly (forward): ";
    DoublyListNode* it = head;
    DoublyListNode* last = nullptr;
    while (it) {
        cout << it->val << " ";
        last = it;
        it = it->next;
    }
    cout << "\nDoubly (backward): ";
    while (last) {
        cout << last->val << " ";
        last = last->prev;
    }
    cout << "\n";
}

void printCircularList(ListNode* head, int limit) {
    cout << "Circular (first " << limit << " nodes): ";
    ListNode* it = head;
    for (int i = 0; i < limit && it; i++) {
        cout << it->val << " ";
        it = it->next;
    }
    cout << "\n";
}

int main() {
    vector<int> vals = {1, 2, 3, 4, 5};
    ListNode* sHead = buildSinglyList(vals);

    Solution sol;
    DoublyListNode* dHead = sol.convertToDoubly(sHead);
    printDoublyList(dHead);

    ListNode* cHead = sol.convertToCircular(sHead);
    printCircularList(cHead, 12);

    return 0;
}
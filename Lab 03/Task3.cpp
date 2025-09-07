#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseLinkedList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr != nullptr) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        return prev;
    }

    ListNode* getKthNode(ListNode* temp, int k) {
        while (temp != nullptr && k > 1) {
            temp = temp->next;
            k--;
        }
        return temp;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == nullptr || k == 1) return head;

        ListNode dummy(0);
        dummy.next = head;
        ListNode* prevGroupEnd = &dummy;

        while (true) {
            ListNode* kthNode = getKthNode(prevGroupEnd->next, k);
            if (kthNode == nullptr) break;

            ListNode* groupStart = prevGroupEnd->next;
            ListNode* nextGroupStart = kthNode->next;

            kthNode->next = nullptr;
            ListNode* newHead = reverseLinkedList(groupStart);

            prevGroupEnd->next = newHead;
            groupStart->next = nextGroupStart;

            prevGroupEnd = groupStart;
        }

        return dummy.next;
    }
};

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = new ListNode(6);
    head->next->next->next->next->next->next = new ListNode(7);
    head->next->next->next->next->next->next->next = new ListNode(8);

    Solution sol;
    int k = 3;
    ListNode* newHead = sol.reverseKGroup(head, k);

    while (newHead) {
        cout << newHead->val;
        if (newHead->next) cout << " -> ";
        newHead = newHead->next;
    }
    cout << "\n";
    return 0;
}
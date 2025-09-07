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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        ListNode dummy(-1);
        ListNode* curr = &dummy;

        while (list1 && list2) {
            if (list1->val < list2->val) {
                curr->next = list1;
                list1 = list1->next;
            } else {
                curr->next = list2;
                list2 = list2->next;
            }
            curr = curr->next;
        }

        //Attaching the remaining part
        curr->next = (list1 ? list1 : list2);

        return dummy.next;
    }
};

int main() {
    ListNode* list1 = new ListNode(1, new ListNode(3, new ListNode(5)));
    ListNode* list2 = new ListNode(2, new ListNode(4, new ListNode(6)));

    Solution sol;
    ListNode* merged = sol.mergeTwoLists(list1, list2);

    while (merged) {
        cout << merged->val;
        if (merged->next) cout << " -> ";
        merged = merged->next;
    }
    cout << "\n";
    return 0;
}
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    int josephus(int n, int k) {
        ListNode* start = new ListNode(1);
        ListNode* cur = start;
        for (int i = 2; i <= n; i++) {
            cur->next = new ListNode(i);
            cur = cur->next;
        }
        cur->next = start;

        ListNode* prev = cur;
        cur = start;
        while (cur->next != cur) {
            for (int step = 1; step < k; step++) {
                prev = cur;
                cur = cur->next;
            }
            prev->next = cur->next;
            ListNode* del = cur;
            cur = cur->next;
            delete del;
        }
        int ans = cur->val;
        delete cur;
        return ans;
    }
};

int main() {
    Solution s;
    int n = 7, k = 3;
    cout << s.josephus(n, k) << "\n";
    return 0;
}
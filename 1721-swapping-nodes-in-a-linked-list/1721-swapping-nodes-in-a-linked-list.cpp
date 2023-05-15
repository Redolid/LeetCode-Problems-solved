/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* first = nullptr;
        ListNode* second = nullptr;

        ListNode* current = dummy;
        for (int i = 0; i < k; i++) {
            current = current->next;
            if (i == k - 1)
                first = current;
        }

        ListNode* slow = dummy;
        ListNode* fast = current;
        while (fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next;
        }
        second = slow->next;

        swap(first->val, second->val);

        return dummy->next;
    }
};

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
    ListNode* swapPairs(ListNode* head) {
    // Base case: If the list has less than 2 nodes, no swapping needed
    if (head == nullptr || head->next == nullptr)
        return head;

    // Swapping the first two nodes
    ListNode* newHead = head->next;
    head->next = swapPairs(newHead->next);
    newHead->next = head;

    return newHead;
}

};
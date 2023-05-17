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
    int pairSum(ListNode* head) {
        int maxSum = INT_MIN;
        ListNode* curr = head;
        vector<int> values;

        // Store the values of the nodes in a vector
        while (curr != nullptr) {
            values.push_back(curr->val);
            curr = curr->next;
        }

        int start = 0;
        int end = values.size() - 1;

        // Iterate over the vector from both ends and calculate the twin sums
        while (start < end) {
            int twinSum = values[start] + values[end];
            maxSum = max(maxSum, twinSum);
            start++;
            end--;
        }

        return maxSum;
    }
};

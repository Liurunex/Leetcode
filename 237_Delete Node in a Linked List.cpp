/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        if (node == NULL) return;
        ListNode* tem = node->next;
        node->val  = tem->val;
        node->next = tem->next;
        delete tem;
        tem = NULL;
    }
};
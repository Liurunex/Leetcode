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
    ListNode* removeElements(ListNode* head, int val) {
        if (!head) return NULL;
        if (head->val != val)
            head->next = removeElements(head->next, val);
        else {
            ListNode* tem = head;
            delete tem;
            tem = NULL;
            head = removeElements(head->next, val);
        }
        return head;
    }
};
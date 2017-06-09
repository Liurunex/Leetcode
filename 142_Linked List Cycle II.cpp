/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/*
    let L = distance of o to s, C = cycle length, X = 1st time meet the distance to s
    (L+X)*2 = L + n*C + X ==> L = nC - X
*/
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (head == NULL || head->next == NULL) return NULL;
        ListNode* fpoint = head;
        ListNode* dpoint = head;
        do {
            fpoint = fpoint->next;
            if (dpoint != NULL && dpoint->next != NULL)
                dpoint = dpoint->next->next;
        } while (dpoint != fpoint);

        if (dpoint == NULL || dpoint->next == NULL) return NULL;

        fpoint = head;
        while (dpoint != fpoint) {
            fpoint = fpoint->next;
            dpoint = dpoint->next;
        } 
        return dpoint;
        
    }
};
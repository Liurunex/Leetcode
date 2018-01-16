/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
private:
	
public:
	RandomListNode *copyRandomList(RandomListNode *head) {
		if (!head) return NULL;
		
		unordered_map<RandomListNode*, RandomListNode*> mapping_table;

		RandomListNode *node = new RandomListNode(head->label);
		mapping_table[head] = node;		

		RandomListNode *dhead = head;
		RandomListNode *dnode = node;

		while (dhead->next) {
			dhead = dhead->next;
			dnode->next = new RandomListNode(dhead->label);
			dnode = dnode->next;
			mapping_table[dhead] = dnode;
		}
		
		dhead = head;
		dnode = node;
		while (dhead) {
			dnode->random = mapping_table[dhead->random];
			dnode = dnode->next;
			dhead = dhead->next;
		}

		return node;		
	}
};

/* the idea: Hash_table + Linked-List. Since it's hard to pair the corresponding random
 * pointer of current node (since that copy object might not created yet), we are using
 * the hash-map to mapping original node pointer to new copy one, that means: the first
 * round we just go through each node and copy itself without considering the random pointer
 * of each object. In the second round, we just iterate to pair each copy object with its
 * corresponding random pointer stroing in our hash-map*/

/* the following idea didn't use extra space, run O(3n); The thought contains 3 steps:
 * step_1: copy each node and append it to origin one, notice it's insertion
 * step_2: pair each copy obejct's random pointer based on the origin
 * step_3: split the copy one with the origin
 */

class Solution {
public:
	RandomListNode *copyRandomList(RandomListNode *head) {
		if (!head) return NULL;
		/* append a copy of each node */
		RandomListNode* node = head;
		while (node) {
			RandomListNode* tem = new RandomListNode(node->label);
			tem->next  = node->next;
			node->next = tem;
			node = tem->next;
		}

		/* mapping random pointer of each copy object */
		node = head;
		while (node) {
			if (node->random)
				node->next->random = node->random->next;
			node = node->next->next;
		}

		/* split origin and copy linked list*/
		node = head;
		RandomListNode *copy_head = node->next;
		while (node) {
			RandomListNode* tem = node->next;
			node->next = tem->next;
			if (tem->next)
				tem->next = node->next->next;
			node = node->next;
		}

		return copy_head;
	}
};
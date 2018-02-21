class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* pre = dummy, *cur = head;
        int need_delete = false;
        
        while(cur) {
            if (cur->next && cur->val == cur->next->val) {
                need_delete = true;
                ListNode* tem = cur->next;
                cur->next = cur->next->next;
                delete tem;
                tem = NULL;
            }
            else if (need_delete) {
                need_delete = false;
                pre->next = cur->next;
                delete cur;
                cur = pre->next;
            }
            else {
                pre = pre->next;
                cur = cur->next;
            }
        }
        head = dummy->next;
        delete dummy;
        dummy = NULL;
        return head;
    }
};

class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == NULL) return root;
        if (key > root->val) root->right = deleteNode(root->right, key);
    	else if (key < root->val) root->left = deleteNode(root->left, key);
    	else if (root->left && root->right) {
			TreeNode* rightMin = root->right;
			while (rightMin->left) 
				rightMin = rightMin->left;

			root->val = rightMin->val;
			root->right = deleteNode(root->right, root->val);
		}
		else {
			TreeNode *tem =root->left? root->left:root->right;
			delete root;
			root = NULL;
			return tem;
		}
		return root;
    }
};
//注解
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return NULL;
        //找值
        if (root->val > key) root->left  = deleteNode(root->left, key);
        else if (root->val < key) root->right = deleteNode(root->right, key);
        //找到要删除点，左右not null
        else if (root->right && root->left) {
            //找左子树max
            TreeNode* rightMin = root->right;
            while (rightMin->left)
                rightMin = rightMin->left;
            // 替换
            root->val = rightMin->val;
            //在左子树delete duplicate
            root->right = deleteNode(root->right, root->val);
        }
        // 左右至少一个null
        else {
            TreeNode* tem = root->left ? root->left:root->right;
            delete root;
            root = tem;
        }
        return root;
    }
};
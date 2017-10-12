class Solution {
public:
	bool verifyPreorder(vector<int>& preorder) {
		int lowest = INT_MIN;
		stack<int> stacker;
		for (int cur:preorder) {
			if (cur < lowest) return false;
			while (!stacker.empty() && stacker.top() < cur) {
				lowest = stacker.top();
				stacker.pop();
			}
			stacker.push(cur);
		}
		return true;
	}
};
/* the idea: we use stack to record the decending part of preorder, which 
 * is from currrent root to its left most one; we also maintain a lowest value
 * to determine the lower_bound, that is once we found any current nodes less than
 * current lowest node, the preorder is wrong; the key is: we keep push node into 
 * stack until we find the current node value > stack.top(), that means we have reached
 * the left most nodes and get to the first right child of some node we have stored in
 * the stack, therefore, we keep pop the stack and update the lowest value until we found
 * the node in stack whcih is parrent of current node we read;
 */

/* another solution: slow but work: the idea is same as verify a BST, that is to set
 * lower_bound and upper_bound for current subtree; once the current node is not in
 * the given interval, then it's wrong; if not, we should find the upperbound node of current
 * root: with the help of BST, we know the current root is the divided point where it's the
 * upperbound of its left subtree and lowerbound of right subtree, so that we wnt to find
 * the first right subtree child and divide the tree into two part to verify the preorder
 */

class Solution {
public:
	bool verifyPreorder(vector<int>& preorder) {
		return helper(preorder, 0, preorder.size()-1, INT_MIN, INT_MAX);
	}
	bool helper(vector<int>& preorder, int start, int end, int low, int upper) {
		if (start > end) return true;
		int curval = preorder[start];
		if (curval > upper || curval < low) return false;
		int upperbound = start+1;
		for (; i <= end; ++ i)
			if (preorder[upperbound] > curval) 
				break;

		return helper(preorder, start+1, upperbound-1, low, curval) &&
		helper(preorder, upperbound, end, curval, upper);

	}
};

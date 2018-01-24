class NumArray {
private:
	struct SeNode {
		int start, end, sum;
		SeNode *left;
		SeNode *right;
		SeNode (int l, int r): start(l), end(r), 
			sum(0), left(NULL), right(NULL) {}
	};
	
	SeNode* build(vector<int>& nums, int l, int r) {
        if (l > r) return NULL;
		SeNode* node = new SeNode(l, r);
		if (l == r) {
			node->sum = nums[l];
			return node;
		}
		int mid = l + (r-l)/2;
		node->left  = build(nums, l, mid);
		node->right = build(nums, mid+1, r);
		node->sum   = node->left->sum + node->right->sum;
		return node;
	}

	int SeQuery(int i, int j, SeNode* node) {
		// not in the range or empty node
		if (!node || node->start > j || node->end < i) 
			return 0;
		// exactualy equal
		if (node->start == i && node->end == j)
			return node->sum;
		// inside case
		int mid = node->start + (node->end-node->start)/2;
		if (i > mid)  return SeQuery(i, j, node->right);
		if (j <= mid) return SeQuery(i, j, node->left);

		return SeQuery(i, mid, node->left) + SeQuery(mid+1, j, node->right);
	}

	void SeModify(int& i, int& diff, SeNode* node) {
		if (!node || node->start > i || node->end < i)
			return;
		node->sum += diff;
		// leaf node case
		if (node->start == node->end)
            return;
		int mid = node->start + (node->end-node->start)/2;
		if (i > mid)
			SeModify(i, diff, node->right);
		else
			SeModify(i, diff, node->left);
	}

	SeNode *root;
	vector<int> dup;

public:
	NumArray(vector<int> nums) {
		root = build(nums, 0, nums.size()-1);
		dup  = nums;
	}

	void update(int i, int val) {
		int diff = val - dup[i];
        dup[i] = val;
		SeModify(i, diff, root);
	}

	int sumRange(int i, int j) {
		return SeQuery(i, j, root);
	}
};

/* the idea: Segment Tree. First recursively build the segment tree until we meet with the single element
 * where left == right, in internal nodes building, made its sum value = left node + right node values, Notice
 * to deal with left > right case where we should return NULL. 
 * Second we consider the query, 3 sub-cases: whenthe query interval is not inside the node range, just return 0;
 * if the query interval exactually equal to the node range, return the node sum value; otherwise, we have to go
 * into the children of node, calculate the mid point to to which child to go or if the query interval overlap with
 * both left and right child, return the sum of both recursive calls.
 * Third we consider update, since we want to know which value to be changed, we mantain a extra duplicate array to 
 * record the current array situation, NOTICE to change the specific value in the duplicate array. We also use recursive
 * call the update our segment tree, we have update all node's value which covered the target index, NOTICE to terminate
 * the recursive call when meet with left == right which is leaf case */

class NumArray {
private:
	vector<int> bitree;
	vector<int> origin;
public:
	NumArray(vector<int> nums) {
		origin.resize(nums.size(), 0);
		bitree = vector<int> (nums.size()+1, 0);
		for (int i = 0; i < nums.size(); ++ i)
			update(i, nums[i]);
	}

	void update(int i, int val) {
		int diff = val - origin[i];
		origin[i] = val;
		int index = i + 1;
		while (index < bitree.size()) {
			bitree[index] += diff;
			index += index & (-index);
		}
	}

	int sumRange(int i, int j) {
		int sum = 0;
		int index = j+1;
		while (index > 0) {
			sum += bitree[index];
			index -= index & (-index);
		}
		index = i;
		while (index > 0) {
			sum -= bitree[index];
			index -= index & (-index);
		}
		return sum;
	}
};

/* the idea: Binary Index Tree;
 * Notice that the update function accept the change-to value, not differnece
 * check Binary Index Tree: http://blog.csdn.net/int64Ago/article/details/7429868
 */
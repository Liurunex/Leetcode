/* the idea: preorder way: we serialize the tree in preorder order, NOTICE we should 
 * record the null node; the deserialize way is to simulate the DFS, build a new node, 
 * recursive DFS to build its left and right subnode;
 *
 * the LevelTravel idea: what leetcode store the tree, BFS ways
 */
/* preorder traversal */
class Codec {
public:
	// Encodes a tree to a single string.
	string serialize(TreeNode* root) {
		string res;
		stack<TreeNode*> serStack;
		serStack.push(root);
		while (!serStack.empty()) {
			TreeNode* node = serStack.top();
			serStack.pop();
			
			if (!node) {
				res += "#,";
				continue;
			}
			
			res += to_string(node->val)+",";

			serStack.push(node->right);
			serStack.push(node->left);
		}
		return res;
	}

	// Decodes your encoded data to tree.
	TreeNode* deserialize(string data) {
		vector<string> preorder;
	
		int node_start = 0;
		for (int i = 0; i < data.length(); ++ i) {
			if (data[i] == ',') {
				preorder.push_back(data.substr(node_start, i - node_start));
				node_start = i+1;
			}
		}
		int index = 0;
		return deserHelper(preorder, index);

	}

	TreeNode* deserHelper(vector<string>& preorder, int& index) {
		if (preorder[index] == "#") return NULL;

		TreeNode* node = new TreeNode(stoi(preorder[index]));
		node->left  = deserHelper(preorder, ++ index);
		node->right = deserHelper(preorder, ++ index);

		return node; 
	}
};

/* level traversal */
class Codec {
public:
	// Encodes a tree to a single string.
	string serialize(TreeNode* root) {
		if (!root) return "";
		string res;
		queue<TreeNode*> serQueue;
		serQueue.push(root);
		while (!serQueue.empty()) {
			TreeNode* node = serQueue.front();
			serQueue.pop();
			
			if (!node) {
				res += "#,";
				continue;
			}
			
			res += to_string(node->val)+",";

			serQueue.push(node->left);
			serQueue.push(node->right);
		}
		cout << res << endl;
		return res;
	}

	// Decodes your encoded data to tree.
	TreeNode* deserialize(string data) {
		if (data.empty()) return NULL;
		vector<string> levelorder;
	
		int node_start = 0;
		for (int i = 0; i < data.length(); ++ i) {
			if (data[i] == ',') {
				levelorder.push_back(data.substr(node_start, i - node_start));
				node_start = i+1;
			}
		}

		int index = 0;
		TreeNode* root = new TreeNode(stoi(levelorder[index++]));
		queue<TreeNode*> deserQueue;
		deserQueue.push(root);
		while (!deserQueue.empty()) {
			TreeNode* node = deserQueue.front();
			deserQueue.pop();

			TreeNode* leftnode  = levelorder[index] == "#" ? NULL:new TreeNode(stoi(levelorder[index]));
			index ++;
			TreeNode* rightnode = levelorder[index] == "#" ? NULL:new TreeNode(stoi(levelorder[index]));
			index ++;

			node->left  = leftnode;
			node->right = rightnode;
			if (leftnode)  deserQueue.push(leftnode);
			if (rightnode) deserQueue.push(rightnode);
		}
		
		return root; 

	}
};

class Solution {
public:
	void connect(TreeLinkNode *root) {
		if (!root) return;
		TreeLinkNode* nextStarter = NULL;
		TreeLinkNode* nextLevelPre = NULL;
		TreeLinkNode* levelPos = root;
		while (levelPos) { 
			/* iterate current level */
			while (levelPos) {
				if (levelPos->left) {
					/* if the next level pre is not NULL, the assign its
					next value, otherwise means the pos->left is the starter
					of next level */
					if (nextLevelPre)
						nextLevelPre->next = levelPos->left;
					else 
						nextStarter = levelPos->left;
					/* no matter what, we should reassign next level pre*/
					nextLevelPre = levelPos->left;
				}

				if (levelPos->right) {
					if (nextLevelPre)
						nextLevelPre->next = levelPos->right;
					else 
						nextStarter = levelPos->right;
					nextLevelPre = levelPos->right;
				}
				/* mvoe to next node on this level */
				levelPos = levelPos->next;
			}

			levelPos = nextStarter;
			nextStarter = NULL;
			nextLevelPre = NULL;
		}
	}
};
/* the idea: we assumed the current level has been assigned next value, then we travel the current level to assign
 * the next level next values. In order to achive this, we need three varaibles: position on current level, started on
 * next level, previous node in next level. Do the travesal level by level, in each level, start from left child, if it's
 * not null, go check the nextLevelPre, if not null, do the assignment, lastly update the nextLevelPre to the current left
 * child; do this for right child same;
 */

class Solution {
public:
	void connect(TreeLinkNode *root) {
		if (!root) return;
		queue<pair<TreeLinkNode*, int>> levelqueue;
		levelqueue.push({root, 0});
		pair<TreeLinkNode*, int> prev = {NULL, 0};

		while (!levelqueue.empty()) {
			auto node = levelqueue.front();
			levelqueue.pop();
			if (node.first != root) {
				if (prev.first && prev.second == node.second)
					prev.first->next = node.first;
				prev = node;
			}
			if (node.first->left)
				levelqueue.push({node.first->left, node.second+1});
			if (node.first->right)
				levelqueue.push({node.first->right, node.second+1});
		}
	}
};

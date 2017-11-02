class Solution {
private:
	struct uNode {
		uNode* parent;
		int val;
		uNode(int nval): val(nval), parent(NULL) {}
	};
	
	uNode* findParent(uNode* onode) {
		uNode* node = onode;
		while (node->parent)
			node = node->parent;
		return node;
	}

	void nodeUnion(uNode* nfrom, uNode* nto) {
		uNode* nfrom_parent = findParent(nfrom);
		uNode* nto_parent   = findParent(nto);
		if (nfrom_parent->val >= nto_parent->val)
			nto_parent->parent = nfrom_parent;
		else nfrom_parent->parent = nto_parent;
	}

public:
	bool validTree(int n, vector<pair<int, int>>& edges) {
        if (!n || n == 1) return true; 
        if (edges.empty()) return false;
		vector<uNode*> nodes (n, NULL);
		for (int i = 0; i < n; ++ i)
			nodes[i] = new uNode(i);
		for (auto pedge:edges) {
			uNode* edge_f = nodes[pedge.first];
			uNode* edge_s = nodes[pedge.second];
			if (findParent(edge_f) == findParent(edge_s))
				return false;
			nodeUnion(edge_f, edge_s);
		}
        
        uNode* root = findParent(nodes[0]);
        for (auto i:nodes) {
            if (findParent(i) != root)
                return false;
        }
		return true;
	}
};
/* the idea: normal Union find question, the only trick parts: one is that we have to
 * check if all nodes hold same "root parent" since there is a invalid tree case where
 * some nodes are connected while others not; the anohter trick is the corner case where
 * the edges is empty or there is less than 2 nodes! 
 */
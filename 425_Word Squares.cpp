class Solution {
private:
	struct Trie {
		char val;
		bool end;
		vector<Trie*> children;
		// prefix is to keep indexes of all words that have the prefix from root to current node 
		vector<int> prefix;
		Trie(char nval): val(nval), end(false), children(26, NULL) {}
	};

public:
	vector<vector<string>> wordSquares(vector<string>& words) {
		//build Trie
		Trie* mytrie = new Trie(' ');
		
		for (int i = 0; i < words.size(); ++ i) {
            string word = words[i];
			Trie* temNode = mytrie;
			for (char curchar:word) {
				int index = curchar-'a';
				if (!temNode->children[index])
					temNode->children[index] = new Trie(curchar);
				temNode = temNode->children[index];
				// added the index to child's prefix vector;
				temNode->prefix.push_back(i);
			}
			temNode->end = true;
		}

		vector<vector<string>> res;
		vector<string> curres (words[0].size());
		for (int i = 0; i < words.size(); ++ i) {
			curres[0] = words[i];
			dfshelper(res, curres, words, 1, mytrie);	
		}
		return res;
	}

	void dfshelper(vector<vector<string>>& res, vector<string>& curres, vector<string>& words, 
		int level, Trie* mytrie) {
		if (level == words[0].size()) {
			res.push_back(curres);
			return;
		}

		Trie* temNode = mytrie;
		for (int i = 0; i < level; ++ i) {
			char tofind = curres[i][level];
			if (!temNode->children[tofind-'a'])
				return;
			temNode = temNode->children[tofind-'a'];
		}

		for (int i:temNode->prefix) {
			curres[level] = words[i];
			dfshelper(res, curres, words, level+1, mytrie);
		}
	}
};

/* the idea: Trie + DFS backtracking(pruning): Why Trie: it provide the linear O(n) time complecity
 * for searching where n is the max length of a word.
 * We implement the DFS and pruning by add a prefix vector into Trie structure: namely, the prefix 
 * vector stores all indexs of words have same prefix so far to current node: like l - e and l - a,
 * the prefix vector of l stores both le and la indexs.
 * Another key point is DFS: since we have the Trie structure, we want to fill the nxn square. How?
 * we filled the form level by level: level 0 is randomly choosen. Once we deterine level i-1 is
 * temporary suitable, we need to check level i, that is to check if the prefix formed by 
 * curres[0][level] ~ curres[level-1][level] is inside the Trie. If so we are temporary safe to continue to
 * next level, otherwise we terminate current case and do backtracking. Notice since we record the prefix
 * index in each node, thuse directly return to prvious recursion and try next possibility is backtracking!
 */
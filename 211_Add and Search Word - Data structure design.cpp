class WordDictionary {
	struct Trie {
		bool isEnd;
		char val;
		vector<Trie *> children;
		Trie(char itval): isEnd(false), val(itval), children(26, NULL) {}
	};
private:
	Trie* root;
public:
	/** Initialize your data structure here. */
	WordDictionary() {
		root = new Trie(' ');
	}

	/** Adds a word into the data structure. */
	void addWord(string word) {
		Trie* node = root;
		for (int i = 0; i < word.length(); ++ i) {
			int index = word[i]-'a';
			if (node->children[index] == NULL) {
				Trie* newTrie = new Trie(word[i]);
				node->children[index] = newTrie;
			}
			node = node->children[index];
		}
		node->isEnd = true;
	}

	/** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
	bool search(string word) {
		Trie* node = root;
		return searchhelper(word, node, 0);
	}
	bool searchhelper(string& word, Trie* node, int start) {
		for (int i = start; i < word.length(); ++ i) {
			if (word[i] == '.') {
				for (int j = 0; j < 26; ++ j) {
					if (node->children[j] != NULL) {
						if (searchhelper(word, node->children[j], i+1))
							return true;
					}
				}
				return false;
			}
			else {
				int index = word[i]-'a';
				if (node->children[index] == NULL)
					return false;
				node = node->children[index];	
			}
		}
		return node && node->isEnd;
	}
};

/* the idea: using trie and we are done most part; the only trick is to deal with '.'
 * in searching, what we do here is a basic dfs searching, once we meet '.', we need
 * to check each not-null elementer in the children vector;
 * the trick: NOTICE to return false after iterate all possible cases mathcing '.' but
 * not yet returing true, since we should say there is no matching but the fucntion
 * will return true for node*node->isEnd!!
 */

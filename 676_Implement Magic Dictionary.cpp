class MagicDictionary {
private:
	struct Trie {
		bool end;
		char val;
		vector<Trie*> children;
		Trie(char input): end(false), val(input), children(26, NULL) {}
	};

	Trie *root;
public:
	/** Initialize your data structure here. */
	MagicDictionary() {
		root = new Trie(' ');
	}

	/** Build a dictionary through a list of words */
	void buildDict(vector<string> dict) {
		for (string word:dict) {
			Trie* node = root;
			for (char chac:word) {
				int index = chac - 'a';
				if (!node->children[index]) {
					Trie* newnode = new Trie(chac);
					node->children[index] = newnode;
				}
				node = node->children[index];
			}
			node->end = true;
		}
	}

	/** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
	bool search(string word) {
		for (int i = 0; i < word.length(); ++ i) {
			char charc = word[i];
			for (char repalce = 'a'; repalce < 'z'; ++ repalce) {
				if (charc == repalce) continue;
				word[i] = repalce;
				if (helperseach(word)) return true;
			}
			word[i] = charc;
		}
		return false;
	}
	
	bool helperseach(string& word) {
		Trie* node = root;
		for (int i = 0; i < word.length(); ++ i) {
			int index = word[i] - 'a';
			if (!node->children[index]) return false;
			node = node->children[index];
		}
		return node->end;
	}
};

/* the idea: using trie here to build the map, the trick is on the search part: since we 
 * should consider all strings that change a character, let's consider "hello" and "hallo"
 * in map and we want to search("hello"), if we just follow normal trie search, we will
 * go thorught hello and get false, but never hallo: the solution is we check each string
 * that exchange its charcater once, using DFS backtracking here, for each "changed" word,
 * we do a normal trie search
 * /
/* a better way is just use hash map to store the whole data stucture, the search part is
 * similar to Trie version, but we can use hash table to check which is O(1)
 */

class MagicDictionary {
private:
	unordered_set<string> mydict;
public:
	/** Initialize your data structure here. */
	MagicDictionary() {}

	/** Build a dictionary through a list of words */
	void buildDict(vector<string> dict) {
		for (string word:dict)
			mydict.insert(word);
	}

	/** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
	bool search(string word) {
		for (int i = 0; i < word.length(); ++ i) {
			char charc = word[i];
			for (char repalce = 'a'; repalce < 'z'; ++ repalce) {
				if (charc == repalce) continue;
				word[i] = repalce;
				if (mydict.count(word)) return true;
			}
			word[i] = charc;
		}
		return false;
	}
};

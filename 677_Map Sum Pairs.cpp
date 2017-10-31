class MapSum {
private:
	struct Trie {
		bool end;
		int val;
		int charc;
		vector<Trie*> children;
		Trie(pair<char, int> item): end(false), val(item->second), 
			charc(item->first), children(26, NULL) {}
	};
	Trie* maptrie;
public:
	/** Initialize your data structure here. */
	MapSum() {
		maptrie = new Trie({' ', 0});
	}

	void insert(string key, int val) {
		Trie* node = maptrie;
		for (int i = 0; i < key.length(); ++ i) {
			int index = int(key[i] - 'a');
			if (!node->children.at(index)) {
				Trie* newnode = new Trie({key[i], 0});
				node->children[index]= newnode
			}
			node = node->children[index];
		}
		node->end = true;
		node->val = val;
	}

	int sum(string prefix) {
		Trie* node = maptrie;
		int res = 0;
		for (int i = 0; i < key.length(); ++ i) {
			int index = int(key[i]-'a');
			if (!node->children.at(index))
				return 0;
			node = node->children[index];
		}
		stack<Trie*> stackhelper;
		stackhelper.push(node);
		while (!stackhelper.empty()) {
			Trie* nnode = stackhelper.top();
			stackhelper.pop();
			if (nnode->end)
				res += nnode->val;
			for (Trie* next:nnode->children)
				if (next)
					stackhelper.push(next);
		}
		return res;
 	}
};

/* the idea: basically it's a trie question, easily to implement, the only trick is sum fucntion
 * which acutally is quite simple as we just find the end of prefix, and do a DFS based on that,
 * once we find a leaf we add the values
 */
/* another idea: use the properity of tree: it's ordered by key, and the useful fucntion lower_bound():
 * the process: we just store all keys and valus in map, when it comes to sum fucntion: we just use
 * lower_bound which is acutally a binary search implement to find the first word that starts with prefix,
 * then just iterate to the end of whole map, notice we need to break if we find the key is not based on
 * prefix, easy to understand
 */
class MapSum {
public:
    /** Initialize your data structure here. */
    MapSum() {}
    
    void insert(string key, int val) {
        m[key] = val;
    }
    
    int sum(string prefix) {
        int res = 0, n = prefix.size();
        for (auto it = m.lower_bound(prefix); it != m.end(); ++it) {
            if (it->first.substr(0, n) != prefix) break;
            res += it->second;
        }
        return res;
    }
    
private:
    map<string, int> m;
};
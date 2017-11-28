class Solution {
private:
	string unionFind(string target, unordered_map<string, string> &unionMap) {
		if (unionMap[target] != target)
			return unionFind(unionMap[target], unionMap);
		else return target;
	}

	void unionMerge(unordered_map<string, string> &unionMap,
		string root_1, string root_2) {
		if (root_1 > root_2)
			unionMap[root_1] = root_2;
		else unionMap[root_2] = root_1;
	}
public:
	bool areSentencesSimilarTwo(vector<string>& words1, vector<string>& words2, 
		vector<pair<string, string>> pairs) {
		if (words2.size() != words1.size()) return false;
		unordered_map<string, string> unionMap;

		for (auto item:pairs) {
			unionMap[item.first] = item.first;
			unionMap[item.second] = item.second;
		}

		for (auto connect:pairs) {
			string root_1 = unionFind(connect.first, unionMap);
			string root_2 = unionFind(connect.second, unionMap);
			if (root_1 != root_2)
				unionMerge(unionMap, root_1, root_2);
		}


		for (int i = 0; i < words1.size(); ++ i) {
			if (words1[i] == words2[i])
				continue;
			string root_1 = unionFind(words1[i], unionMap);
			string root_2 = unionFind(words2[i], unionMap);
			if (root_1 == root_2)
				continue;
			return false;
		}
		return true;
	}
};

/* the idea: union-find + DFS. We first do a union operation on all nodes, determine its root with
 * union merge. We then do the loop: each time we just check if two string share same root in union_map
 * is enough: since if two word is in transitively similarity, their root must be the same, that's where
 * union find helps!
 */
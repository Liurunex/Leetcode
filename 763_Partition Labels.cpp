class Solution {
public:
	vector<int> partitionLabels(string S) {
		unordered_map<char, int> dict;
		for (int i = 0; i < S.size(); ++ i)
			dict[S[i]] = i;
        vector<int> partition;
        int rightMost = 0, start = 0;
		for (int i = 0; i < S.size(); ++ i) {
			if (dict[S[i]] > rightMost)
				rightMost = dict[S[i]];
			if (i == rightMost) {
				partition.push_back(i+1-start);
                start = i+1;
				rightMost = i+1;
			}
		}
		return partition;
	}
};

/* the idea: Greedy. 存下每个char出现的最远index，然后开始遍历，记录当前遍历到的
 * 的string中的char出现最远的index，不断更新这个值，当发现当前index == 目前需要到达的
 * 最远的index，就找到了一例，记录其长度
 * */
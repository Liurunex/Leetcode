class Solution {
public:
	vector<string> topKFrequent(vector<string>& words, int k) {
		unordered_map<string, int> dict;
		for (string curword:words)
			dict[curword] ++;
		auto comparator = [](pair<string, int>x, pair<string, int>y) -> bool {
			if (x.second > y.second) return true;
			if (x.second == y.second && x.first < y.first ) return true;
			return false; };
		priority_queue<pair<string, int>, vector<pair<string, int>>, 
			decltype(comparator)> pq(comparator);
		
		for (auto iter = dict.begin(); iter != dict.end(); iter ++) {
			pq.push({iter->first, iter->second});
			if (pq.size() > k)
				pq.pop();
		}

		vector<string> res;
		while (!pq.empty()) {
			res.push_back(pq.top().first);
			pq.pop();
		}
		reverse(res.begin(), res.end());
		return res;
	}
};
/* the idea: just use hash map to mapping word to its frequency, then we use a prioirty_queue
 * to find our top k, the key idea is to rewrite the comparator of priority queue, we use lambda
 * expression here, notice priority queue cannot accept a object comparator as sort fucntion do, so
 * that we have to use decltype to convert object to type, and notice the way of new a pq using 
 * our new comparator! we keep the mini pq with size k, finally we just pop items into a vector and
 * reverse the vector and we are done;
 * the trick: notice the comparator should take care of the tie case where we should return result on
 * alphabet order
 * /
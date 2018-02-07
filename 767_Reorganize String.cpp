class Solution {
public:
	string reorganizeString(string S) {
		vector<int> dict(26, 0);
		for (char c:S)
			dict[c-'a'] ++;

		
		auto comp = [](pair<int, char> x, pair<int, char> y) -> bool {
			return x.first < y.first;
		};
        priority_queue<pair<int, char>, vector<pair<int, char>>, decltype(comp)> pq(comp);
		for (int i = 0; i < dict.size(); ++ i) {
			if (dict[i] > (S.size()+1)/2) return "";
			if (dict[i])
				pq.push({dict[i], i+'a'});
		}
		string str;
		while (pq.size() > 1) {
			auto even = pq.top();
			pq.pop();
			auto odd = pq.top();
			pq.pop();
			str += even.second;
            str += odd.second;
			even.first --;
			odd.first --;
			if (even.first)
				pq.push(even);
			if (odd.first)
				pq.push(odd);
		}
        if (pq.size() == 1)
            str += pq.top().second;
		return str; 
	}
};
/* the idea: Greedy. 统计所有char出现次数，然后以pair input到priority_queue 里面，如果有发现某个char出现
 * 出现次数超过(n+1)/2，则不能按照要求构造string，否则，我们按照规则构造string，不断pop出两个，append后再push
 * */
/* the hint idnicates only to update the start and end value, that is: add value at start, minus value at end+1 */
class Solution {
public:
	vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
		vector<int> res (length, 0);

		for (int i = 0; i < updates.size(); ++ i) {
			res[updates[i].at(0)]   += updates[i].at(2);
			if (updates[i].at(1)+1 < res.size())
				res[updates[i].at(1)+1] -= updates[i].at(2);
		}

		for (int i = 1; i < res.size(); ++ i)
			res[i] += res[i-1];

		return res;
	}
};
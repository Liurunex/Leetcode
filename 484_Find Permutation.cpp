class Solution {
public:
	vector<int> findPermutation(string s) {
		if (!s.length()) return {};
		int n = s.length()+1;
		vector<int> res (n, 0);
		for (int i = 0; i < res.size(); ++ i)
			res[i] = i+1;
		
		int index = 0, reverse = 0;
		while (index < s.length()) {
			if (s[index] == 'D') {
				reverse = index+1;
				while (reverse < s.length() && s[reverse] == 'D')
					reverse ++;
				
				doReverse(index, reverse, res);

				index = reverse;
			}
			else index ++;
		}
		return res;
	}
	
	void doReverse(int start, int end, vector<int>& res) {
		cout << start << " " << end << " doReverse\n";
		stack<int> stackhepler;
		for (int i = start; i <= end; ++ i)
			stackhepler.push(res[i]);
		int index = start;
		while (!stackhepler.empty()) {
			res[index] = stackhepler.top();
			stackhepler.pop();
			index ++;
		}
	}
};
/* the idea: in order to get the lexicographically smallest permutaion, we first sort the
 * array in ascending order; the key idea is that we observe that only we meet the 'D' in
 * string we need do the reverse, that is: once we meet a 'D', we find the longest 'D' 
 * substring, this part substring correspodning the part we should reverse in our res
 * array, take a look at this example:
 * D D I I D I
 * 1 2 3 4 5 6 7
 * ^ ^ #   ^ #
 * 3 2 1 4 6 5 7
 * Notice that 'D' substring jsut correspond to the subarray we should do the reverse 
 * to satisfy the 'Decresing' notation
 */

class Solution {
public:
    vector<int> findPermutation(string s) {
        vector<int> res;
        for (int i = 0; i < s.size() + 1; ++i) {
            if (i == s.size() || s[i] == 'I') {
                int size = res.size();
                for (int j = i + 1; j > size; --j) {
                    res.push_back(j);
                }
            }
        }
        return res;
    }
};
/* antoher solution: we don't use reverse, but similar to it, we keep insert items in 
 * reverse order when meeting 'I'
 */

class Solution {
private:
	struct Trie {
		int val;
		int number;
		vector<Trie*> nextdigit;
		Trie(int newval): val(newval), number(NULL), nextdigit(2, NULL) {}
	};

	void buildTire(vector<int>& nums) {
		treenodes = new Trie(-1);
		for (int num:nums) {
			Trie* node = treenodes;
			for (int i = 31; i >= 0; -- i) {
				int bvalue = (num >> i) & 1;
				if (!node->nextdigit[bvalue])
					node->nextdigit[bvalue] = new Trie(bvalue);
				node = node->nextdigit[bvalue];
			}
			node->number = num;
		}
	}
	
	int maxHelper(int target) {
		Trie* node = treenodes;
		for (int i = 31; i >= 0; -- i) {
			int bvalue = (target >> i)&1;
			bvalue = bvalue == 1 ? 0:1;
			if (!node->nextdigit[bvalue])
				bvalue = bvalue == 1 ? 0:1;
			node = node->nextdigit[bvalue]; 
		}
		return node->number ^ target;
	}

public:
	int findMaximumXOR(vector<int>& nums) {
		buildTire(nums);
		int res = INT_MIN;
		for (int num:nums)
			res = max(res, maxHelper(num));
		return res;
	}
private:
	Trie* treenodes;
};

/* the idea: Trie idea: notice the number will < 2^31, that means each number can be
 * represented by a 31 digit binary number; therefore we are trying to store each
 * number as the 31 digit binary form into our Trie structure, the Trie will have
 * 31 levels, and each leaf much contain a decimal value, NOTICE we store each 
 * number of its binary form from hight digit to lower digit, this is important;
 * for the search part, we convert the target number into the one's complement form
 * since it's known that the XOR resutl is maximium when X ^ X's one's complement,
 * then we search the Trie struture, we want a number that is structurely similar to
 * our target's one's complement, follow this process we will find the resutl
 */

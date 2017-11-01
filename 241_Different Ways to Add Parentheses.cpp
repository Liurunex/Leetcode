class Solution {
public:
	vector<int> diffWaysToCompute(string input) {
		unordered_map<string, vector<int>> dict;
		return divide_conquer(input, dict);
	}
	vector<int> divide_conquer(string input,
		unordered_map<string, vector<int>>& dict) {
		/* already calculated case */
		if (dict.count(input)) return dict[input];

		bool all_digit = true;
		vector<int> curvalues;
		for (int i = 0; i < input.length(); ++ i) {
			if (input[i] < '0' || input[i] > '9') {
				all_digit = false;
				vector<int> left_values  = divide_conquer(input.substr(0, i), dict);
				vector<int> right_values = divide_conquer(input.substr(i+1), dict);
				
				for (int left_v:left_values) {
					for (int right_v:right_values) {
						switch (input[i]) {
							case '+': curvalues.push_back(left_v + right_v); break;
							case '-': curvalues.push_back(left_v - right_v); break;
							case '*': curvalues.push_back(left_v * right_v); break;
						}
					}
				}
			}
		}
		if (all_digit) curvalues.push_back(stoi(input));
		dict[input] = curvalues;
		return curvalues;
	}
};
/* the idea: divide and conquer, we check the input string, once we find a opeartor at
 * position i, we divide the problem into two subproblem (0..i) +/-/* (i..end), since 
 * there are multiple possible values for once string so that our return value have to
 * be vector, the process is: we go through the string, once we meet opearator, we do
 * a divide and conquer, notice here we just push all possible values into return vector
 * since there is still other dividing ways existed, therefore we have to check the whole
 * input; here we use a alldigit boolean vlaue to determine if current input is a pure
 * number, if so we just push it as values into return vector. One more ting, we use 
 * a hash map to record all computed string mapping to its value vectors, so that to avoid 
 * redundant computation.
 */
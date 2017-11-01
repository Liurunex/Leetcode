class Solution {
public:
	bool checkValidString(string s) {
		stack<char> leftpa, startpa;
		for (int i = 0; i < s.length(); ++ i) {
			if (s[i] == '(') leftpa.push(i);
			else if (s[i] == '*') startpa.push(i);
			else {
				if (leftpa.size()) leftpa.pop();
				else if (startpa.size()) startpa.pop();
				else return false;
			}
		}

		while (!leftpa.empty()) {
			if (startpa.empty() || startpa.top() < leftpa.top())
				return false;
			startpa.pop();
			leftpa.pop(); 
		}
		return true;
	}
};
/* the idea: greedy thougths, two stack, leftpa stroing index of '(', starpa storing index of '*'
 * the process is two steps: STEP ONE: iterate the string, if we meet '(', push it
 * into leftpa, if meet '*', push into startpa, or in the case of ')', the greedy thoughts applid here,
 * that is: we first consider pop a '(' to offset, if not possible, we try '*' using as '(', otherwise
 * we cannot offset ')' but retur false;
 * STEP TWO: now we only have '(' and '*', we want to pair each '(' with '*' as the order form like "(*",
 * notice there is no way to decode "*(", that's reason why our stack records the index!! On basis of that
 * we then just check if the top of leftpa is highter than top of startpa, NOTICE we use stack here, that
 * means the last one go out first
 * the thougths behind: the pair way here is not the true mehod we use, consider (*(**), we are expecting ')'
 * pairing wiht the first '(', but in we actually pair it with the second '(', but this thougth can work to
 * determine if valid. So WHY? this is beacuse in STEP ONE we elminate all ')' by pairing it wiht '(' or '*',
 * think about (*(**) in real we get *(**, in our method we get (***, the two form has same result of true, 
 * that lead use to get a result of (*(*)), the difference is how we reach the state, but dones't matter!!
 */
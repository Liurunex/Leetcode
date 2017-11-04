/* O(1) space*/
class Solution {
public:
	int calculate(string s) {
		int global = 0, local = 0;
		char presymbol = '+';
		for (int i = 0; i < s.size(); ++ i) {
			if (s[i] == ' ') continue;
			
			if (s[i] >= '0' && s[i] <= '9') {
				int number = s[i]-'0';
				while ((++ i) < s.size() && s[i] >= '0' && s[i] <= '9')
                    number = number*10 + s[i]-'0';
				i --;
				switch (presymbol) {
					case '+': local += number; break;
					case '-': local -= number; break;
					case '*': local *= number; break;
					case '/': local /= number; break;
				}
			}
			else {
				if (s[i] == '+' || s[i] == '-') {
					global += local;
					local = 0;
				}
				presymbol = s[i];
			}
		}
		return global + local;
	}
};
/* THE IDEA: basci idea using vector/stack to storing "valid" number, where "valid" number is the operator
 * ahead will not be '*' or '/'. The key thought: we keep iterate the string, once meet a number, we extract
 * it and see the previous symbol, if it's '*' or '/', calculating the res and push into the vector, since
 * now it is vaid number! NOTICE to judege the negative number. If we meet wiht symbol, only update it
 * when it's priority symbol '*' or '/'! Finally we add all number into our res in vector since vector 
 * now storing all valid only with operator '+'!
 * THE BETTER IDEA: O(1) space and O(n) time: we use global to record our total res, and local record the
 * sum results of single number or computation with priority opeartor '*' or '/': once we meet a number,
 * extract it and compute the result based on previous symbol, assign it to local; once we meet a symbol,
 * if it's lower priority '+' or '-', we update our global and set local to 0, remeber we should update the
 * symbol in this condition. NOTICE return should be global + local since last time local doesn't add to global
 * Why this works: each time we meet '+' or '-', we will update gobal and reset local, that means local actually
 * is the sum after computation and will keep until we meet lower priority symbol: give 3+4/2, local is 3, 2; given
 * 4/2+3, local is 2, 3. So that local compute on each opaertoers but when we meet symsbol, we might reset it
 * to achive that local value passed to next iteartion is the result that will be applied with high priority 
 * symbol (since we will update the symbol!)
 */

class Solution {
public:
	int calculate(string s) {
		vector<int> toadd;
		int isnegative = 1, res = 0;
		char presymbol = '+', negtivesymbol = '+';
		for (int i = 0; i < s.size(); ++ i) {
			if (s[i] == ' ') continue;
			
			if (i < s.size() && s[i] >= '0' && s[i] <= '9') {
				int number = 0, pushres = 0;
				while (s[i] >= '0' && s[i] <= '9')
					number = number*10 + s[i ++]-'0';
                i --;
				isnegative = negtivesymbol == '-'? -1:1;
				pushres = number*isnegative;
	
				switch (presymbol) {
					case '*':
						pushres = toadd.back() * pushres;
						toadd.pop_back();
						break;
					case '/':
                        pushres = !pushres ? 1:pushres;
						pushres = toadd.back() / pushres;
						toadd.pop_back();
						break;
				}
                presymbol = '+'; // IMPORTANT!!
                negtivesymbol = '+'; // IMPORTANT !!
				toadd.push_back(pushres);
			}
			else {
				if (s[i] == '*' || s[i] == '/')
					presymbol = s[i];
				else negtivesymbol = s[i];
			}
		}

		for (int item:toadd)
			res += item;
		return res;
	}
};

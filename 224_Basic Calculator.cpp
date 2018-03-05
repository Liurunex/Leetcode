class Solution {
public:
    int calculate(string s) {
        char symbol = '+';
        int local = 0;
        stack<pair<int, char>> vals;
        
        for (int i = 0; i < s.size(); ++ i) {
            if (s[i] == ' ') continue;
            if (s[i] >= '0' && s[i] <= '9') {
                int num = s[i ++]-'0';
                while (i < s.size() && s[i] >= '0' && s[i] <= '9')
                    num = num*10 + s[i ++]-'0';
                i --;
                switch (symbol) {
                    case '+': local += num; break;
                    case '-': local -= num; break;
                }  
            }
            else if (s[i] == '(') {
                vals.push({local, symbol}); //必须有符号信息，不然pop出来做运算的符号已变
                local = 0;
                symbol = '+'; // 符号也要重置
            }
            else if (s[i] == ')') {
                auto pre = vals.top();
                vals.pop();
                switch (pre.second) {
                    case '+': local += pre.first; break;
                    case '-': local = pre.first - local; break; // 出来时被减数
                }
            }
            else symbol = s[i];
        }
        return local;
    }
};


/*basic calculator*/
class Solution {
public:
	int calculate(string s) {
		stack<pair<int, char>> prepos;
		int res = 0, local = 0;
		char presymbol = '+';
		
		for (int i = 0; i < s.size(); i ++) {
			
			/* if it's number, extract the number, add it to local based on pre-symbol, notice
			 * the pre-symbol '(' is work as '+', no case to meet ')'
			 */
			if (s[i] >= '0' && s[i] <= '9') {
				int number = s[i]-'0';
				while ((++ i) < s.size() && s[i] >= '0' && s[i] <= '9')
					number = number*10 + s[i]-'0';
				i --;

				switch (presymbol) {
					case '(':
					case '+': local += number; break;
					case '-': local -= number;
				}
			}
			/* if it's a symbol: CASE '+'/'-': just simply update the global res, and reset local;
			 * CASE '(': it indicates the we are moving into a sub-computation, so that we store
			 * our preious res and symbol in stack, NOTICE storing pre-symbol is needed as we need
			 * to know if we should do +/- when meeting ')' and updating total-res, here we should
			 * reset res, since we are get into a sub-computation, where the res is used as a sub-res
			 * and should be initilized; CASE ')' (NOTICE case"((3))", the second '(' is unnecessary;
			 * CASE ')': it indicates we should pop from stack and update res, here the stored pre-symbol
			 * make sense as to determine -/+, NOTICE we should update sum of (local+sub-res), since the
			 * final round local will not be added into sub-res, remeber to reset local;
			 */
			else {
				/* in case there is some white spaces */
                if (s[i] != '+' && s[i] != '-' && s[i] != '(' && s[i] != ')')
					continue;
				switch (s[i]) {
					case '+':
					case '-': res += local; local = 0; break;
					case '(': {
						if (presymbol == '(') 
							break;
						prepos.push({res, presymbol}); 
						res = 0; // local has set to 0
						break;
					}
					case ')': {
						if (!prepos.empty() && prepos.top().second != '(') {
							int sign = prepos.top().second == '+' ? 1:-1;
							/* NOTICE:: the final round local will not be added into sub-res */
							res = sign * (local+res) + prepos.top().first;
							local = 0;
						}
						prepos.pop(); 
						break;
					}
					
				}
				presymbol = s[i];
			}
		}
		/* NOTICE:: the final round local will not be added into res */
		return res+local;
	}
};

/* the idea: we use stack to dealing with (), that is once we meet (, push current res and pre-symbol
 * into stack, once we meet ), we pop the top from stack and update the res. Detail description see code
 */

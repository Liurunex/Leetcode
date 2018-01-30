class Solution {
public:
    int calculate(string s) {
        stack<int> values;
        stack<char> symbols;
        int local = 0;
        symbols.push('+');

        for (int i = 0; i < s.size(); ++ i) {
            if (s[i] == ' ') continue;
            if (s[i] >= '0' && s[i] <= '9') {
                int num = s[i]-'0';
                while ((++i) < s.size() && s[i] >= '0' && s[i] <= '9')
                    num = num*10 + s[i]-'0';
                -- i;
                switch (symbols.top()) {
                    case '+': values.push(num); break;
                    case '-': values.push(num*-1);break;
                    default: {
                        int tem = values.top();
                        values.pop();
                        tem = symbols.top() == '*' ? tem*num : tem/num;
                        values.push(tem);
                        /* necessary */
                        symbols.pop();
                    }
                }
            }
            else if (s[i] == '(') {
                values.push(0);
                values.push(0);
                symbols.push('(');
                symbols.push('+');
                local = 0;
            }
            else if (s[i] == ')') {
                while (values.size() && symbols.size()) {
                    if (symbols.top() == '(') {
                        values.pop();
                        values.pop();
                        symbols.pop();
                        switch (symbols.top()) {
                            case '+': values.push(local); break;
                            case '-': values.push(local*-1);break;
                            default: {
                                int tem = values.top();
                                values.pop();
                                tem = symbols.top() == '*' ? tem*local : tem/local;
                                values.push(tem);
                                /* necessary */
                                symbols.pop();
                            } 
                        }
                        break;
                    }
                    local += values.top();
                    values.pop();
                    symbols.pop();
                }
                local  = 0;
            }
            else symbols.push(s[i]);
        }
        while (values.size()) {
            local += values.top();
            values.pop();
        }
        return local;
    }
};
/* the idea: Two Stacks. 使用两个stack，维持二者size balance，一个记录符号，一个记录值，符号stack的top是最近的符号，遍历整个string：
 * 遇到number：正常处理，算出值，看符号stack的top，加减入栈，乘除修改value stack的top，同时把symbol stack的top pop！
 * 遇到符号：push into symbol stack
 * 遇到(: value stack 压入两个0，用于和symbol stack位置补齐，因为symbol stack现在比value stack多一个，进入( 后相当于dfs进入下轮recursive call，
 * 也就是local要reset，同时symbol stack要压入(，用于标记括号起始位置，同时压入一个 + 用于括号内计算重置！
 * 遇到 ): 不停从value 和 symbol stack pop，不断更新local，知道symbol stack 遇到(,即为之前标记的括号开始位置，然后把括号内的值与其外进行合并，
 * 方法和遇到+-/* 一样的， 记得local要reset，因为出括号了！
 * */
class Solution {
public:
	int calculate(string s) {
		int i = 0;
		return partCal(s, i);
	}
	
	int partCal(string& s, int& i) {
		stack<int> res;
		int local = 0;
		char symbol = '+';
		while (i < s.size()) {
			if (s[i] == ' ') { 
                ++ i; 
                continue;
            };
			/* number case: */
			if (s[i] >= '0' && s[i] <= '9') {
				int num = s[i]-'0';
				while ((++i) < s.size() && s[i] >= '0' && s[i] <= '9')
					num = num*10 + s[i]-'0';
				-- i;
				switch (symbol) {
					case '+': res.push(num); break;
					case '-': res.push(num*-1);break;
					default: {
						int tem = res.top();
						res.pop();
						tem = symbol == '*' ? tem*num : tem/num;
						res.push(tem);
					}
				}
			}
			else if (s[i] == '(') {
				int part = partCal(s, ++ i);
				switch (symbol) {
					case '+': res.push(part); break;
					case '-': res.push(part*-1); break;
					default: {
						int tem = res.top();
						res.pop();
						tem = symbol == '*' ? tem*part : tem/part;
						res.push(tem);
					}
				}
			}
			else if (s[i] == ')') {
				while (res.size()) {
					local += res.top();
					res.pop();
				}
				return local;
			}
			else {
				symbol = s[i];
			}
			++ i;
		}
		while (res.size()) {
			local += res.top();
			res.pop();
		}
		return local;
	}
};
/* the idea: Stack + DFS. 记录之前的符号，维护一个stack，存之前每一计算的值：
 * 当遇到number，计算值，然后根据之前符号push到stack，注意*和/二者
 * 当遇到(时候，dfs进入括号内，recursive 调用
 * 当遇到)时候，把stack里面的值都push出来累加后返回上一层
 * 当遇到符号，更新符号record
 * 最后遍历结束，把stack里面的值都push出来累加后返回为答案
 * 总的来说，stack处理+-/*, dfs处理括号
 * */
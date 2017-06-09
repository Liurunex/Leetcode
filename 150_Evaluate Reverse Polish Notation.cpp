class Solution {
public:
    int evalRPN(vector<string>& tokens) {
		stack<int> Tem;
		int i = 0;
		string tar ="+-*/";
		for (i = 0; i < tokens.size(); i++) {
			if (tar.find(tokens[i]) == string::npos) 
				Tem.push(atoi(tokens[i].c_str()));
			else {
				int a = Tem.top();
				Tem.pop();
				int b = Tem.top();
				Tem.pop();
				int res = 0;
                if (tokens[i] == "+") 
                    res = a + b;
                if (tokens[i] == "-") 
                    res = b - a;
                if (tokens[i] == "*") 
                    res = a * b;
                if (tokens[i] == "/") 
                    res = b / a;
				Tem.push(res);
			}
		}
		return Tem.top();   
    }
};
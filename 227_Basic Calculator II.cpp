// stack 保存全部只有+/-操作的数
class Solution {
public:
    int calculate(string s) {
        stack<int> vals;
        char symbol = '+';
        
        for (int i = 0; i < s.size(); ++ i) {
            if (s[i] == ' ') continue;
            if (s[i] >= '0' && s[i] <= '9') {
                int num = s[i++]-'0';
                while (i < s.size() && s[i] >= '0' && s[i] <= '9')
                    num = num*10 + s[i ++]-'0';
                i --;
                switch (symbol) {
                    case '+': vals.push(num); break;
                    case '-': vals.push(-1*num); break;
                    case '*': vals.top() *= num; break;
                    case '/': vals.top() /= num; break;
                }
            }
            else symbol = s[i];
        }
        
        int res = 0;
        while (vals.size()) {
            res += vals.top();
            vals.pop();
        }
        return res;
    }
};
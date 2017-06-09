class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> front = {0,1};
        vector<int> current;
        if (n < 0) return current;
        if (n == 0) return {0};
        if (n == 1) return front;
        int round = 1;
        int prefix = 2;
        while (round < n) {
        	current = front;
        	for (int i = front.size()-1; i >= 0; i --) 
        		current.push_back(prefix + front[i]);
        	prefix <<= 1;
        	round ++;
        	front = current;
        }
        return current;
    }
};
class Solution {
public:
    vector<string> generateParenthesis(int n) {
    	int i = 0, left = 0, right = 0;
    	vector<string> res;
    	string add;
    	addnew(res, add, left, right, n);
    	return res;  	
    }

   	void addnew(vector<string>& res, string add, int left, int right, int n) {
   		if (add.size() == n*2) {
   			res.push_back(add);
   			return;
   		}
   		if (left < n) {
   			add += "(";
   			addnew(res, add, left+1, right, n);
   			add.erase(add.size()-1);
   		}
   		if (right < left) {
   			add += ")";
   			addnew(res, add, left, right+1, n);
   			add.erase(add.size()-1);
   		}
   	}
};
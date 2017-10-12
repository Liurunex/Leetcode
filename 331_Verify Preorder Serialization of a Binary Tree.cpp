/* solution 1 using outdegree and indgree: in any case, outdegree >= indegree */
class Solution {
public:
	bool isValidSerialization(string preorder) {
		if (preorder.size() < 1 || (preorder.size() == 1 && preorder[0] == '#')) 
			return true;
		stringstream ss(preorder);
		string tok;
		int degree = 0;
		int rootTime = 1;
		while (getline(ss, tok, ',')) {
			if (rootTime) {
				if (tok == "#")
					return false;
				degree = 2;
				rootTime = 0;
				continue;
			}
			if (tok == "#")
				degree --;
			else degree ++;
			
            if (degree <= 0)
				break;
		}
		return degree == 0 && !getline(ss, tok, ',');
	}
};

class Solution {
public:
	bool isValidSerialization(string preorder) {
	    if (preorder.size() < 1 || (preorder.size() == 1 && preorder[0] == '#')) return true;

	    preorder += ',';
		int differ = 0;
		if (preorder[0] != '#')
		    differ = 2;
	    int i = 0;
	    while (preorder[i] != ',')
	        i ++;
	    i ++;
		for (; i < preorder.size(); i ++) {
		    if (differ <= 0 && i != preorder.size()-1)
				return false;
		    if (preorder[i] != ',')
		        continue;
			if (preorder[i-1] == '#')
				differ --;
			else differ ++;
		}
		return differ == 0;
	}
};


/* solution 2 using stack */
class Solution {
public:
	bool isValidSerialization(string preorder) {
		stack<string> tem;
		istringstream iss(preorder);
		string tok;
		while (getline(iss, tok, ',')) {
			while (tok == "#" && tem.size() >= 2 && tem.top() == "#") {
			    string top = tem.top();
				tem.pop();
				if (tem.top() != "#")
				    tem.pop();
			    else {
			        tem.push(top);
			        break;
			    }
			}
			tem.push(tok);
		}
		return (tem.top() == "#" && tem.size() == 1);
	}
};

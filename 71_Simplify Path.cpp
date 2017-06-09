class Solution {
public:
	string simplifyPath(string path) {
		stack<string> pstack;
		string tem = "", res = "/";
		for (int i = 0; i < path.size(); i++) {
			switch (path[i]) {
				case '/': tem.clear(); break;
				case '.': 
					if (tem.empty()) {tem += "."; break;}
					if (tem == ".") {
						if (i == path.size()-1 || 
							(i < path.size()-1 && path[i+1] == '/')) {
							if (!pstack.empty()) pstack.pop();
							break;
						}
					}  
				default: 
					tem += path[i];
					if (i < path.size()-1 &&  path[i+1] == '/') pstack.push(tem);
					else if (i == path.size()-1) pstack.push(tem);
			}
		}

		while (!pstack.empty()) {
			if (pstack.size() == 1)
				res.insert(1, pstack.top());
			else  res.insert(1, "/" + pstack.top());
			pstack.pop();
		}
		return res;
	}
};
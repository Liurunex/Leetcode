/* 425 ms*/
class Solution {
public:
	vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
		for (int i = 0; i < pid.size(); ++ i) {
			if (kill == pid[i] && ppid[i] == 0)
				return pid;
		}
		int done = 1;
		vector<int> res;
		queue<int> deleteChild;
		deleteChild.push(kill);
		while (!deleteChild.empty()) {
			int tokill = deleteChild.front();
			deleteChild.pop();
			res.push_back(tokill);

			for (int i = 0; i < ppid.size(); ++ i) {
				if (ppid[i] == tokill)
					deleteChild.push(pid[i]);
			}
		}
		return res;
	}
};

/* 202 ms*/
class Solution {
public:
	vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
		for (int i = 0; i < pid.size(); ++ i) {
			if (kill == pid[i] && ppid[i] == 0)
			return pid;
		}
		unordered_map<int, vector<int>> ppid_pid;
		for (int i = 0; i < ppid.size(); ++ i) {
			if (ppid_pid.find(ppid[i]) == ppid_pid.end()) {
				vector<int> addnew;
				addnew.push_back(pid[i]);
				ppid_pid[ppid[i]] = addnew;
			}
			else ppid_pid[ppid[i]].push_back(pid[i]);
		}
		vector<int> res;
		queue<int> deleteChild;
		deleteChild.push(kill);
		while (!deleteChild.empty()) {
			int tokill = deleteChild.front();
			deleteChild.pop();
			res.push_back(tokill);

			for (int i = 0; i < ppid_pid[tokill].size(); ++ i)
				deleteChild.push(ppid_pid[tokill].at(i));
		}
	return res;
	}
};

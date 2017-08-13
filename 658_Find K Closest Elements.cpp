class Solution {
public:
	vector<int> findClosestElements(vector<int>& arr, int k, int x) {
		int closet, pre, later, insert = x, find = 1;
		vector<int> res;
		for (int i = 0; i < arr.size(); ++ i) {
			if (arr[i] == x) { closet = i; break; }
			if (arr[i] > x) {
				if (find) { find = 0; closet = i; }
				int tem = arr[i];
				arr[i]  = insert;
				insert  = tem;
			}
		}
		if (!find && arr.back() <= insert) arr.push_back(insert);
		
		for (int i = 0; i < arr.size(); ++ i) 
			cout << arr[i] << " ";
		cout << endl;
		
		pre   = closet - 1;
		later = closet + 1;
		cout << pre << " " << later;
		if (find) res.push_back(x);
		while (k > find) {
			k --;
			if (pre >= 0 && later < arr.size()) {
				if (x-arr[pre] <= arr[later]-x){
					res.push_back(arr[pre]);
					pre --;
				}
				else {
					res.push_back(arr[later]);
					later ++;
				}
			}
			else if (pre < 0 && later >= arr.size()) break;
			else if (pre < 0) { res.push_back(arr[later]); later ++; }
			else { res.push_back(arr[pre]); pre --; }
		}
		sort(res.begin(), res.end());
		return res;
	}
};
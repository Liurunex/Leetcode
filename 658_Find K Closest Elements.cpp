class Solution {
public:
	vector<int> findClosestElements(vector<int>& arr, int k, int x) {
		int lbindex = bst_lower_bound(arr, x);
		int left = lbindex-1, right = lbindex;
		while (k --) {
			if (left < 0 || (right < arr.size() && abs(arr[left]-x) > abs(arr[right]-x)))
				right ++;
			else left --;
		}
		return vector<int> (arr.begin()+left+1, arr.begin()+right);
	}

	int bst_lower_bound(vector<int>& arr, int x) {
		int left = 0, right = arr.size()-1;
		while (left <= right) {
			int mid = left + (right-left)/2;
			if (arr[mid] == x) {
				while (arr[mid] == x) {
					mid --;
					if (mid < 0) return 0;
				}
				return mid+1;
			}
			else if (arr[mid] > x) right = mid-1;
			else left = mid+1; 
		}
		return left;
	}
};
/* the idea: we are going to find the closet value to target, then we 
 * start at this point, using two pointers to compare left and right
 * side and keep this process unitl k == 0;
 * the trick: how to find the lower_bound in array of the target,
 * instead of using lower_bound built_in fucntion, we can use Binary
 * Search, NOTICE that once we find the target, we must loop for back
 * to find the first target!!!
 */
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

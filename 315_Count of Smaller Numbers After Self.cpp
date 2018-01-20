class Solution {
private:
	void merge(vector<pair<int, int>>& arr, vector<int>& res, int l, int m, int r) {
		vector<pair<int, int>> leftpart  (arr.begin()+l, arr.begin()+m+1);
		vector<pair<int, int>> rightpart (arr.begin()+m+1, arr.begin()+r+1);

		int left_p = 0, right_p = 0, ori_p = l, count = 0;
		while (left_p < leftpart.size() && right_p < rightpart.size()) {
			if (leftpart[left_p].first <= rightpart[right_p].first) {
				/* left <= right -> no more smaller value in rest right can be found, so update left coutner! */
				res[leftpart[left_p].second] += count;
                arr[ori_p ++] = leftpart[left_p ++];
            }
			else {
				/* left > right -> all rest in left will have ++ count of smaller value! */
                count ++;
				arr[ori_p ++] = rightpart[right_p ++];
			}
		}
		while (left_p < leftpart.size()) {
            res[leftpart[left_p].second] += count;
            /* much important, since the rest left should update its count!!! */
			arr[ori_p ++] = leftpart[left_p ++];
        }
        while (right_p < rightpart.size())
			arr[ori_p ++] = rightpart[right_p ++];
	}

	void mergeSort(vector<pair<int, int>>& nums, vector<int>& res, int l, int r) {
		if (l < r) {
			int m = l + (r-l)/2;
			mergeSort(nums, res, l, m);
			mergeSort(nums, res, m+1, r);
			merge(nums, res, l, m, r);
		}
	}
public:
	vector<int> countSmaller(vector<int>& nums) {
		vector<int> res (nums.size(), 0);
		/* instead of using index array, using pair to directly bound value with index is easy to implement */
		vector<pair<int, int>> copynums;
		for (int i = 0; i < nums.size(); ++ i)
			copynums.push_back({nums[i], i});
        
		mergeSort(copynums, res, 0, copynums.size()-1);
        
		return res;
	}
};

/* the idea: Merge Sort. Basically its a untilization of merge sort, we do the normal merge sort, but this time
 * we bound the value with index as a element so that we can access the original index after merge sort change it.
 * The key point is in merge part: once we get two sorted array left and right, we then want to merge them into a
 * original array. we set the left_ptr, right_ptr and ori_ptr pointing to the three arrays, NOTICE we need a varaible
 * count to record how many inversion appears in this time:
 * do normal merge sort process on sorted left and right array:
 * if left[left_ptr] > right[right_ptr] -> we increase count since we find a inversion, the count helps since all rest
 * element of left should count that inversion! But we don't update the inversion count for left[left_ptr]!
 * if left[left_ptr] <= right[right_ptr] -> the left_ptr has no more smaller value in right, so that we are safe to update
 * the inversion count for left_ptr, and also we are easy to acess the orginal index of left_ptr as we bound them!
 * The trick is: when we then iterate the rest of left, we must update the inversion count of those element! That's beacuse
 * we have run out all right, the rest of left should have same inversion # as the current value of count! 
 * */

class Solution {
public:
	vector<int> countSmaller(vector<int>& nums) {
		vector<int> sorted;
		vector<int> res (nums.size(), 0);

		for (int i = nums.size()-1; i >= 0; -- i) {
			int left = 0, right = sorted.size()-1;
			while (left <= right) {
				int mid = left + (right-left)/2;
				if (nums[i] > sorted[mid])
					left = mid+1;
				else right = mid-1;
			}
			res[i] = left;
			sorted.insert(sorted.begin()+left, nums[i]);
		}
		return res;
	}
};

/* the idea: Binary Search; We noticed that, if we insert the number from
 * backforwad into a array which is intial empty, the index we insert the 
 * number is the # of smaller valuer to current number! That is the key 
 * thought, therefore we need to form a empty array, keep inserting the elements
 * from original array into it, and the insert position is the # of smaller vlaues.
 * So that iterate each number, do binary search on sorted array, then update our
 * result array, but notice this method is O(n^2) in worest case! */
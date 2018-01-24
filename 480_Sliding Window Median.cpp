class Solution {
public:
	vector<double> medianSlidingWindow(vector<int>& nums, int k) {
		vector<double> res;
		multiset<int> lefthal, righthal;
		for (int i = 0; i < nums.size(); ++ i) {
			// need to remove the left-most element
			if (i >= k) {
				int target = nums[i-k];
				if (lefthal.count(target))
					lefthal.erase(lefthal.find(target));
				else if (righthal.count(target))
					righthal.erase(righthal.find(target));
			}
			// insert node into two heap
			// case 1: lefthal has smaller size
			if (lefthal.size() < righthal.size()) {
				if (nums[i] < *righthal.begin()) {
					lefthal.insert(nums[i]);
				}
				else {
					lefthal.insert(*righthal.begin());
					righthal.erase(righthal.begin());
					righthal.insert(nums[i]);
				}
			}
			// case 2: righthal has smaller size or equal size
			else {
				// both empty case
				if (!lefthal.size())
					righthal.insert(nums[i]);
				else if (nums[i] > *lefthal.rbegin()) {
					righthal.insert(nums[i]);
				}
				else {
					righthal.insert(*lefthal.rbegin());
					lefthal.erase(--lefthal.end());
					lefthal.insert(nums[i]);
				}
			}
			// update the res by adding current median
			if (i >= k-1) {
				if (k&1) 
					res.push_back(*righthal.begin());
				else 
					res.push_back(((double)*righthal.begin() + *lefthal.rbegin())/2.0);
			}
		}
		return res;
	}
};
/* the idea: Min-Heap + Max-Heap (multiset). We do the almost same thing like median of
 * data stream question. The difference we need to maintain the size sum of two heap stay
 * at k. Because of that, we use multiset instead of priority queue since the latter one donesn't
 * provide erase function. The we maintain that the left-max-heap and the right-min-heap has a
 * size difference at most 1. Then two cases to consider:
 * case 1: left-max-heap has smaller size: if nums[i] < min of right-min-heap, then just normally
 * insert the value into left, otherwise, we should move the right-min from right to left, and insert
 * the value into right. 
 * case 2: righ-max-heap has smaller or equal size: almost same as prvious except the size = 0 case.
 * Trick 1: before inserting new value, we should remove the nums[i-k] from heaps, since it's outside
 * the k-size window [i-k+1, i];
 * Trick 2: once we insert a new into heaps, we then will find the median, this is differ on odd and even
 * k.
*/
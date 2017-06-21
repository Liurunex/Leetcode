/*
 BinarySearch slolution, O(nlogn)
 */
class Solution {
public:
	int findDuplicate(vector<int>& nums) {
		int i = 0, j = 0;
		int leftlimit = 1, rightlimit = nums.size()-1;
		int searchrange = 0;
		while (leftlimit <= rightlimit) {
			searchrange = leftlimit + (rightlimit - leftlimit)/2;
			int count = 0;
			for (int i = 0; i < nums.size(); ++ i)
				if (nums[i] <= searchrange)
					count ++;		
			if (count > searchrange) 
				rightlimit = searchrange - 1;
			else leftlimit = searchrange + 1;		
		}
		return leftlimit;	
	}
};

/*
 Tow pointer, "Linked List" solution, O(1);
 https://segmentfault.com/a/1190000003817671
 http://keithschwarz.com/interesting/code/?dir=find-duplicate
 */

class Solution {
public:
	int findDuplicate(vector<int>& nums) {
		int slow = nums[0], fast = nums[nums[0]];
		while (slow != fast) {
			slow = nums[slow];
			fast = nums[nums[fast]];
		}	
		fast = 0;
		while (fast != slow) {
			slow = nums[slow];
			fast = nums[fast];
		}
		return fast;
	}
};
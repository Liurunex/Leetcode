class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int leftbound = 0, rightbound = nums.size()-1;
        while (leftbound < rightbound) {
        	int mid = leftbound + (rightbound - leftbound)/2;
			if (nums[mid] == nums[mid+1]) {
				if ((nums.size()-1 - mid - 1) % 2 == 0)
					rightbound = mid - 1;
				else leftbound = mid + 2;
			}
			else if (nums[mid] == nums[mid-1]) {
				if ((mid-1) % 2 == 0)
					leftbound = mid + 1;
				else rightbound = mid - 2;
			}
			else return nums[mid];
        }
        return nums[leftbound];
    }
};

/* the idea: Binary Search + condition judege; the trick part
 * is how to determine which part divided by mid should we go.
 * What we are doing here is to judge if mid value is the single value
 * that is compaing with mid-1 and mid+1 index values. If nums[mid] = nums[mid+1]
 * that indicates we should check if the right side rest numbers has a size of odd or
 * even: that is mid mid+1 mid+2...end, we check if mid+2 ... end has odd or even size
 * checking that means if the rest has even number, the rest must be all pairs, otherwise
 * we will get two single value, which violate our rules. Following this rule, we can then
 * determine which part to go. Do the same case when nums[mid] = nums[mid-1]. That's where
 * BS takes place.
 *
 * */
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
    	if (nums.size() < 2) return nums[0];
    	if (nums.size() % 2 == 0) return NULL;
        int leftbound = 0, rightbound = nums.size()-1;
        while (leftbound < rightbound) {
        	int mid = leftbound + (rightbound - leftbound)/2;
        	if (mid % 2 == 0) {
	        	if (nums[mid] == nums[mid-1]) 
	        		rightbound = mid - 2;
	        	else if (nums[mid] == nums[mid+1])
	        		leftbound = mid + 2;
	    		else return nums[mid];
	    	}
	    	else {
	    		if (nums[mid] == nums[mid-1]) 
	        		leftbound = mid + 1;
	        	else if (nums[mid] == nums[mid+1])
	        		rightbound = mid - 1;
	    	}
        }
        return nums[leftbound];
    }
};

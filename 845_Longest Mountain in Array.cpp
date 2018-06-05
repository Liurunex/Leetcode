class Solution {
public:
	int longestMountain(vector<int>& A) {
		int n = A.size();
		if (n < 3)
			return 0;
		int left = 0, right = 1, res = 0;
		
		while (right < n) {
            // find the first increasing subarray start at current position
            while (right < n && A[left] >= A[right]) {
                left ++;
                right ++;
                
            }

            // check if there is a incresaing one
            if (right >= n) {
                break;
            }
			// incresaing subarray
			int pre = A[left];
			while (right < n && pre < A[right]) {
				pre = A[right];
				right ++;
			}

            // check if there is a decreasing one, NOTE must update left and right here
            if (right >= n || pre == A[right]) {
                left = right;
                right ++;
                continue;
            }
            
			// decresing subarray
			while (right < n && pre > A[right]) {
				pre = A[right];
				right ++;
			}
			
			// update
			res = max(right - left, res);
			left = right-1;
		}
		return res;
	}
};

/* the idea: two points + sliding window, the tirck is to check if increasing and drecresaing
   sub-array exist. NOTICE that check for decreasing subarray we must reset the left and right
   if non-decreasing array found, this is to termintate the impact of tie case */
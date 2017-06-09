// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
    	int lowbound = 1, upperbound = n, res = -1, mid = -1;
		while (lowbound <= upperbound) {
			mid = lowbound + (upperbound - lowbound)/2;
			if (isBadVersion(mid)) {
				res = mid;
				upperbound = mid - 1;
			}
			else lowbound = mid + 1;
			
		}
		return res;
    }
};
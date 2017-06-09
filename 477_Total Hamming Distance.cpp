/* cout #0 x #1 at each bit*/
class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int res = 0;
        for (int i = 0; i < 32; i++) {
        	int count = 0;
        	for (int num: nums) {
        		count += (num >> i) & 1;
        	}

        	res += count * (nums.size() - count);
        }
        return res;
    }
};


/* TLE */
class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        if (nums.size() < 2) return 0;
        int i = 0, j = 0, res = 0;
        for (i = 0; i < nums.size(); i++)
        	for(j = i+1; j < nums.size(); j++)
        		res += HammningDistance(nums[i], nums[j]);
    	return res;
    }

    int HammningDistance(int m, int n) {
    	if (m == n) return 0;
    	int x = m ^ n;
        x = (x & (0x55555555)) + ((x >> 1) & (0x55555555));
        x = (x & (0x33333333)) + ((x >> 2) & (0x33333333));
        x = (x & (0x0f0f0f0f)) + ((x >> 4) & (0x0f0f0f0f));
        x = (x & (0x00ff00ff)) + ((x >> 8) & (0x00ff00ff));
        x = (x & (0x0000ffff)) + ((x >> 16) & (0x0000ffff));
    	return x;
    }
};

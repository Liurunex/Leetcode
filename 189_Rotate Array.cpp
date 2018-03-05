// Swap 大法
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int start = 0, n = nums.size();
        k %= n;
        while (k) {
            for (int i = 0; i < k; ++ i)
                swap(nums[start+i], nums[start+ n-k + i]);
            start += k;
            n -= k;
            k %= n;
        }
    }
};

// reverse 大法
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k %= n; 
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin()+k);
        reverse(nums.begin()+k, nums.end());
    }
};

class Solution {
public:
	void rotate(vector<int>& nums, int k) {
		if (!nums.size() || !(k%nums.size())) return;
		k %= nums.size();
		for (int i = 0; i < nums.size()-k; ++ i) {
			nums.push_back(nums[0]);
			nums.erase(nums.begin());
		}
	}
};
/* the idea is to append first n-k elements to the end the whole
 * array, and delete the first element simultanesouly again and again,
 * simialar to the reverse method, but easily for implement
 * NOTICE: need k%n first
 */


class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if (nums.empty()) return;
        int n = nums.size(), start = 0;   
        while (n && (k %= n)) {
            for (int i = 0; i < k; ++i) {
                swap(nums[i + start], nums[n - k + i + start]);
            }
            n -= k;
            start += k;
        }
    }
};

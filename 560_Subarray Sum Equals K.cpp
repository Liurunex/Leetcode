class Solution {
public:
	int subarraySum(vector<int>& nums, int k) {
		int res = 0, target = k;
		unordered_map<int, int> pre_sum;
		pre_sum[0] ++;
		int sum = 0;
		for (size_t i = 0; i < nums.size(); ++ i) {
			sum += nums[i];
			if (pre_sum.find(sum - target) != pre_sum.end())
				res += pre_sum[sum - target];
			pre_sum[sum] ++;
		}
		return res;
	}
};
/* the idea: we will use cultimative sum deadling question about constiguous subsum,
 * here the instance is: we use a hashmap to record all cultimative subsum and the times
 * it appears (this is necessary as non-posotive number might be involved); the process is
 * we keep a variable to record current cultimative subsum, using the eqution:
 * clusum[j]-culsum[i] = target, we record the culsum[i] inside hashmap, we compute the 
 * culsum[j] and we hold the target to find; on the basis of that, we will try to update 
 * the res;
 */

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int cum=0; // cumulated sum
        map<int,int> rec; // prefix sum recorder
        int cnt = 0; // number of found subarray
        rec[0]++; // to take into account those subarrays that begin with index 0
        for(int i=0;i<nums.size();i++){
            cum += nums[i];
            cnt += rec[cum-k];
            rec[cum]++;
        }
        return cnt;
    }
};







class Solution {
public:
	int maximumGap(vector<int>& nums) {
		if (nums.size() < 2) return 0;
		int maxnum = 0, minnum = INT_MAX;
		for (size_t i = 0; i < nums.size(); ++ i) {
			maxnum = max(maxnum, nums[i]);
			minnum = min(minnum, nums[i]);
		}
	
		int bucket_size = (maxnum - minnum) / nums.size() + 1;
		//int bucket_size = (maxnum - minnum) / (nums.size()-1);
		//if (!bucket_size) bucket_size = 1;
		int bucket_numb = (maxnum - minnum) / bucket_size + 1;
		
		vector<pair<int, int>> bucket (bucket_numb, make_pair(-1, -1));

		for (size_t i = 0; i < nums.size(); ++ i) {
			int index = (nums[i] - minnum) / bucket_size;

			if (bucket[index].first == -1) {
				bucket[index].first  = nums[i];
				bucket[index].second = nums[i];
				continue; 
			}

			bucket[index].first  = max(bucket[index].first, nums[i]);
			bucket[index].second = min(bucket[index].second, nums[i]);
		}


		int res_gap = 0;
		for (size_t i = 1, j = 0;  i < bucket.size(); ++ i) {
			if (bucket[i].first == -1) continue;
			res_gap = max(res_gap, bucket[i].second - bucket[j].first);
			j = i;
		}
		return res_gap;
	}
};
/*
be care about the bucket size and count
 */
/*
maximum gap would not be less than the ceiling [(B - A) / (N - 1)]
assign single bucket's length = ceiling[(B - A) / (N - 1)], we then get at most (B - A) / len + 1 buckets 
compute corresponding bucket index for each number in nums[] by loc = (K - A) / len
notice the max gap must produced by the adjacent buckets;
let's find the next non-empty bucket for current one, the candiate is next.min - cur.max
 */

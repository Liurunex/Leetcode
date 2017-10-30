class Solution {
public:
	bool isPossible(vector<int>& nums) {
		unordered_map<int, int> dict;
		for (int i = 0; i < nums.size(); ++ i)
			dict[nums[i]] ++;
		
		unordered_map<int, int> tail;
		for (int curnum:nums) {
			if (!dict[curnum]) continue;
			if (tail.count(curnum) && tail[curnum] > 0) {
				dict[curnum] --;
				tail[curnum] --;
				tail[curnum+1] ++;
			}
			/* try to new a subsequence starting from curnum */
			else if (dict[curnum+1] && dict[curnum+2] > 0) {
				dict[curnum]   --;
				dict[curnum+1] --;
				dict[curnum+2] --;
				tail[curnum+3] ++;
			}
			else return false;
		}
		
		return true;
	}
};
/* the idea: we use two hash map: dictFreq mapping the number to its frequency
 * while the other hash map tail mapping the number which can append to a valid
 * sequnce to its requested time: e.g. nums[1,2,3,3,4,5], after we "construct"
 * subsequnce [1,2,3], we are expecting 4 for once, so that the tail hashmap 
 * grant tail[4] -> 1; 
 * the process: three cases to consider: FIRST -> if the frequency of the num is 0, that
 * means the number has bee totally used in previous to construct vaild subarray, then skip;
 * SECOND -> if we find tail[num] > 0, that means the previous valid subarray are recruiting
 * current num to join them, in this case, we just decrease tail[num] and dictFrequency[num],
 * and more important, we shall increase tail[num+1] since now we are expecting num+1;
 * THIRD -> if neighter happened, we consider to check if the current num can form a valid
 * subarray start from itself, is so we keep iteratio, otherwise return false
 * /
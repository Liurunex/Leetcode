class Solution {
private:
	vector<int> nums;
public:
    Solution(vector<int> nums) {
        this->nums = nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return nums;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
    	vector<int> snums (this->nums.begin(), this->nums.end());
        for (int i = snums.size()-1; i > 0; -- i) {
			int sindex    = rand() % (i+1);
			int tem       = snums[sindex];
			snums[sindex] = snums[i];
			snums[i]      = tem;
        }
        return snums;
    }
};
/* the idea is to use Fisher–Yates shuffle Algorithm: we start from back to
 * front, randomly choose a index by using rand() fucntion, then swap it
 * with the "current last" element ith, we keep repeating this process until
 * we reach the first element
 */

/* alteranteive solution: we just randomly generate a index which is the 
 * sequence of array we want to return in 'alphabeat' order, then consider
 * the way we used in 60_permutation sequnce to find that sequence in
 * constant time
 */


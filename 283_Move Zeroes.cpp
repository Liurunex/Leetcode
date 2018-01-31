class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int left = 0, right = 0;
        while (nums[left])
            left ++;
        right = left+1;
        while (left < right && left < nums.size() && right < nums.size()) {
            if (nums[right]) {
                swap(nums[left], nums[right]);
                while (nums[left])
                    left ++;
                right = left + 1;
            }
            right ++;
        }
    }
};
/* the idea: Two pointer. 左pointer指向目前第一个0，右pointer指向左pointer后的第一个非0，然后
 * 我们做swap交换，同时左pointer更新到下一个新的第一个0处, 接着右pointer不断++，这样就可以maintain order
 * */
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int left = 0, right = 0;
        while (right < nums.size()) {
            if (nums[right]) {
                swap(nums[left ++], nums[right]);
            }
            right ++;
        }
    }
};

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = 0, n = 0;
        for (i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                nums.erase(nums.begin()+i);
                i --;
                n ++;
            }
        }
        while (n > 0) {
            nums.push_back(0);
            n --;
        }
    }
};
// tow pointer
class Solution {
public:
    int trap(vector<int>& height) {
        int res = 0, left = 0, right = height.size()-1;
        
        while (left < right) {
            if (height[left] < height[right]) {
                int minleft = height[left];
                left ++;
                while (left < right && height[left] < minleft)
                    res += minleft - height[left ++];
            }
            else {
                int minright = height[right];
                right --;
                while (left < right && height[right] < minright)
                    res += minright - height[right --];
            }
        }
        return res;
    }
};

/* double direction pointers, pointer array repalce single pointer */
class Solution {
public:
    int trap(vector<int>& height) {
        if (height.size() < 3) return 0;
		int water = 0;
		vector<int> leftheight (height.size(), 0);
		vector<int> rightheight (height.size(), 0);
		/* initial left height for each element */
		for (int i = 1; i < height.size(); i++)
			leftheight[i] = max(leftheight[i-1], height[i-1]);

		/* set right height for each elemnt and caculate water on i */
		for (int j = height.size()-2; j >= 1; j--) {
			rightheight[j] = max(rightheight[j+1], height[j+1]);
			int minheight = min(rightheight[j], leftheight[j]);
			if (height[j] < minheight) 
				water += minheight - height[j];
		}
		return water;
    }
};
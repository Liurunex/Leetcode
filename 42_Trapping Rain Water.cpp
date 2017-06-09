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
		for (int j = height.size()-2; j >= 0; j--) {
			rightheight[j] = max(rightheight[j+1], height[j+1]);
			int minheight = min(rightheight[j], leftheight[j]);
			if (height[j] < minheight) 
				water += minheight - height[j];
		}
		return water;
    }
};
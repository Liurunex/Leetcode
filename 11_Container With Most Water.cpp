class Solution {
public:
	int maxArea(vector<int>& height) {
		if (height.size() < 2) return 0;

		int area = 0, leftbound = 0, rightbound = height.size()-1;
		while (leftbound < rightbound) {
			int curarea = min(height[rightbound], height[leftbound]) * (rightbound - leftbound);
			area = max(area, curarea);
			if (height[rightbound] < height[leftbound])
				rightbound --;
			else if (height[rightbound] > height[leftbound])
				leftbound ++;
			else if (height[rightbound] == height[leftbound]) {
				leftbound ++;
				rightbound --;
			}
		}
		return area;
	}
};
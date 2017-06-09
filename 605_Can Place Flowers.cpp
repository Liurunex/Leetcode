class Solution {
public:
	bool canPlaceFlowers(vector<int>& flowerbed, int n) {
		for (int i = 0; i < flowerbed.size(); ++ i) {
			if (n == 0) return true;
			if (flowerbed[i] == 0) {
				if (((i-1 >= 0 && flowerbed[i-1] != 1) || i-1 < 0) &&
				((i+1 < flowerbed.size() && flowerbed[i+1] != 1) || i+1 >= flowerbed.size())) {
					n --;
					if (i-1 >= 0) flowerbed[i-1] = -1;
					if (i+1 < flowerbed.size()) flowerbed[i+1] = -1;
				}
			}
		}
		return n == 0;
	}
};

class Solution {
public:
	vector<int> asteroidCollision(vector<int>& asteroids) {
		//vector<int> res;
		vector<int> positives;
		for (int cur:asteroids) {
			if (cur > 0)
                positives.push_back(cur);
			else if (cur < 0) {
				while (positives.size() > 0 && positives.back() > 0) {
					int pos = positives.back();
					positives.pop_back();
					if (pos + cur > 0) {
						positives.push_back(pos);
						cur = 0;
						break;
					}
					else if (pos + cur == 0) {
						cur = 0;
						break;
					}
				}
				if (cur != 0)
					positives.push_back(cur);
			}
		}
		return positives;
	}
};
/* the idea: Stack thougt. 用一个stack来simulate，遇到正数，直接入栈，遇到负数，不断从栈里
 * pop出正数出来，判断能否抵消，最后发现栈里面没有正数可用就把负数入栈，repeat this process*/
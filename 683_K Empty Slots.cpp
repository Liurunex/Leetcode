class Solution {
public:
	int kEmptySlots(vector<int>& flowers, int k) {
		if (flowers.size() < 2) return -1;
		if (flowers.size() == 2) {
			if (!k) return 2;
			else return -1;
		}

		vector<int> position (flowers.size(), 0);

		for (int i = 0; i < flowers.size(); ++ i) {
			int pos = flowers[i];
			position[pos-1] = 1;
			int leftmost= pos-2,rightmost = pos;

			while (leftmost >= 0 && !position[leftmost]) leftmost --;
			while (rightmost < position.size() && !position[rightmost]) rightmost ++;

			if ((leftmost >= 0 && position[leftmost] && pos-1-leftmost == k+1) || 
				(rightmost < position.size() && position[rightmost] && rightmost-pos+1 == k+1)) {
				return i+1;
			}
		}
		return -1;
	}
};

/* the idea: brute force, what we do is simply iterate each day, make the flower i open at its
 * position, then we traverl from that position to check the left and right boundary where the
 * another flower is open, then calculate the distance between left to pos and pos to right
 * respectively, check if it was equal to k, otherwise we keep iterating until reach the final
 * day.
 * BETTER: using set, which is treemap as ordered set, so each time we insert cost O(logn),
 * the find the leftmost and rightmost cost O(1) since we only need adjacent nodes, so that
 * totally it is O(nlogn)
 */

class Solution {
public:
	int kEmptySlots(vector<int>& flowers, int k) {
		if (flowers.size() < 2 || flowers.size < k) return -1;
		if (flowers.size() == 2) {
			if (!k) return 2;
			else return -1;
		}

		set<int> position;

		for (int i = 0; i < flowers.size(); ++ i) {
			int pos = flowers[i];
			set<int>::iterator set_itr = position.insert(pos-1).first;
			auto leftmost = set_itr, rightmost = set_itr;
			
			if (leftmost != position.begin() && pos-1-*(-- leftmost) == k+1 || 
				(++ rightmost) != position.end() && *(rightmost)-pos+1 == k+1)
				return i+1;
		}
		return -1;
	}
};
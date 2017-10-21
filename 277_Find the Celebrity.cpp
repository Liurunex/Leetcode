bool knows(int a, int b);

class Solution {
public:
	int findCelebrity(int n) {
		int candiate = 0;
		for (int i = 0; i < n; ++ i) {
			if (knows(candiate, i))
				candiate = i;
		}

		for (int i = 0; i < n; ++ i)
			if (candiate != j && knows(candiate, i) || !knows(i, candiate))
				return -1;

		return candiate;
	}
};
/* the idea: the inital idea is to test each one as a candidate, that means
 * we will do a O(n^2) nested for loop, here is a trick to accelerate the
 * performance that is once we found a know candidates, we should set a as
 * not a candiate and we will ignore it when iterateing to it;
 *
 * the better one: the one pass solution is one pass: we set the first
 * person 0 as the candidate, then go through other peoeple to test
 * know(candidate, i), once we find candidate know i, then switch the i to 
 * the candidate, until we check all in one pass: the reason: let candidate = k,
 * k start at 0, we iterate i from 1 to n-1, if knows(k, i) -> k is not candidate,
 * but i might be, in other case, k don't know i, then i is not candiate, but k
 * keep its candidate position! therefore we can get one normal people in a check!
 * finally we check whetehr the candidate is a real cerlebrity
 */


// Forward declaration of the knows API.
bool knows(int a, int b);

class Solution {
public:
	int findCelebrity(int n) {
		vector<int> candiates(n, 1);
		for (int i = 0; i < n; ++ i) {
			if (!candiates[i]) continue;
			for (int j = 0; j < n; ++ j) {
				if (i == j) continue;
				if (knows(i, j) || !knows(j, i)) {
					candiates[i] = 0;
					break;
				}
				else candiates[j] = 0;
			}
			if (candiates[i]) return i;
		}
		return -1;
	}
};

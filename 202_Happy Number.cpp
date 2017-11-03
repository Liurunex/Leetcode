class Solution {
public:
	bool isHappy(int n) {
		unordered_set<int> dict;
		while(n != 1) {
			int next = 0;
			while (n) {
				next += pow((n%10), 2);
				n /= 10;
			}
			n = next;
			if (n == 1) break;
			if (dict.count(n)) break;
			dict.insert(n);
		}
		return n == 1;
	}
};
/* the idea: hash set: the key is once we meet a next number which has appeared but is not 1, 
 * we have found that the number is not happy
 * the brilliant idea: two pointers view each number we generate as a node, then it's like a find loop
 * question in linkedlist!
 */
class Solution {
public:
	bool isHappy(int n) {
		int slow = n, fast = n;
		while(1) {
			slow = digitPow(slow);
			fast = digitPow(digitPow(fast));
			if (slow == fast) break;
		}
		return slow == 1;
	}
	int digitPow(int n) {
		int next = 0;
		while (n) {
			next += pow((n%10), 2);
			n /= 10;
		}
		return next;
	}
};
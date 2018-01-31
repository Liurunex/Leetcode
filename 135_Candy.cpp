class Solution {
public:
	int candy(vector<int>& ratings) {
		vector<int> candies (ratings.size(), 1);
		for (int i = 1; i < ratings.size(); ++ i) {
			if (ratings[i] > ratings[i-1])
				candies[i] = candies[i-1]+1;
		}

		for (int i = ratings.size()-2; i >= 0; --i) {
			if (ratings[i] > ratings[i+1])
				candies[i] = max(candies[i], candies[i+1]+1);
		}

		int res = 0;
		for (int can:candies)
			res += can;
		return res;
	}
};
/* the idea: Greedy. initial 每个人有1个candy，向右扫一遍，遇到右边ratting大的，
 * 增加其candy数目为左边小的+1，然后向左扫一遍，同理操作：这样第一次iteration保证了向左方向
 * 的关系，再向右遍历确保另一个方向的关系，最后累计. NOTICE: 第二次遍历更新的时候要写Max函数！
 */

/* one run solution: 记录递减区间
http://www.cnblogs.com/grandyang/p/4575026.html*/
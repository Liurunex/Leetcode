class Solution {
public:
	vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
		sort(people.begin(), people.end(), [](pair<int, int> x, pair<int, int> y) {
			if (x.first == y.first) return x.second < y.second;
			return x.first > y.first;
		});
		vector<pair<int, int>> res;
		for (auto person:people) {
			res.insert(res.begin()+person.second, person);
		}
		return people;
	}
};
/* the idea: greedy; we sort the vector by height from higher to low, if eaqul height,
 * sort by k value (min go first). Why do this: greedy thought: the person with higher
 * height will have lower k value, and NOTICE: person's sorted position i >= its k value,
 * since all people ahead him is higher! The we do our reconstruciton: for a new vector,
 * we just keep insert the person to the k position. Why: for ith person will have k higher
 * people ahead, his previous people list is in relative correct position, that means 0..i-1
 * people sorted done, for the ith person, if i == k, we are done, since there is exactually
 * i peeople higher or equal than himself, if i != k and we know i > k, i person should at the
 * k position, so that there is k people higher ahead him, due to that, we just insert ith person
 * into the kth position at the new vector !!
 * Analyze: O(n) space, O(n^2) time
 * the follwing is O(1) space, O(2n^2) time: same thought, after sort
 * if we find i person should plcace at k, we just erase the i person, notice the erasion would 
 * not affect people order from 0 to i-1, then we just insert i person to the k position, which
 * is jsut simulate the same opeartion of insert into new vector!
 */
class Solution {
public:
	vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
		sort(people.begin(), people.end(), [](pair<int, int> x, pair<int, int> y) {
			if (x.first == y.first) return x.second < y.second;
			return x.first > y.first;
		});

		for (int i = 0; i < people.size(); ++ i) {
			auto person = people[i];
			if (i != person.second) {
				people.erase(people.begin()+i);
				people.insert(people.begin()+person.second, person);
			}
		}

		return people;
	}
};

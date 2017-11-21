class Solution {
public:
	int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
		if (beginWord.size() != endWord.size()) return 0;
		unordered_set<string> wordSet (wordList.begin(), wordList.end());
		queue<pair<string, int>> bfsqueue;
		bfsqueue.push({beginWord, 1});
		while (!bfsqueue.empty()) {
			pair<string, int> transfer = bfsqueue.front();
			bfsqueue.pop();

			if (transfer.first == endWord)
				return transfer.second;

			for (int i = 0; i < transfer.first.size(); ++ i) {
				char tem = transfer.first.at(i);
				for (int j = 0; j < 26 ; ++ j) {
					if (transfer.first.at(i) == 'a'+j) continue;
					transfer.first.at(i) = 'a'+j;
					if (wordSet.count(transfer.first)) {
						bfsqueue.push({transfer.first, transfer.second+1});
						wordSet.erase(transfer.first);
					}
				}
				transfer.first.at(i) = tem;
			}
		}

		return 0;
	}
};
/*the idea: using DFS is brute-force solution which cannot pass; the idea here we use is BFS
 * which is a simplified Dijistra Algorithm; we first convert the question into a graph where
 * given a start point and try to find the shortest path to the target; the edge exist where two
 * string have a distance of 1; Then we have convert the string problem into a shortest path in 
 * graph one; 
 * NOTICE: instead of building a same-size visiting graph, we decisde to mark the choosen one pushing
 * into queue to empty string in dictionary, or we first convert the dictionary into a unordered_set
 * and then delete it
 * NOTICE: the overhead is finding the edges of a string, normal method is to go through the whole dictionary
 * and check if the word has 1 distnce from our curstr, another one is way to wise: we change the curstr on each
 * digit from 'a' to 'z', and count if the new string exsit in the dictionary set, if so we push it into queue and 
 * remove it from dictionary(here we don't need worry about the order), the reason is the words number in dictionary
 * can be huge while the word length is always stay in 100 digits, therefore the later one is better than former one
 * */

class Solution {
public:
	int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
		if (beginWord.size() != endWord.size()) return 0;
		int shortest = INT_MAX;
		queue<pair<string, int>> bfsqueue;
		bfsqueue.push({beginWord, 1});
		while (!bfsqueue.empty()) {
			pair<string, int> transfer = bfsqueue.front();
			bfsqueue.pop();

			if (transfer.first == endWord) {
				shortest = min(shortest, transfer.second);
				continue;
			}
			for (int i = 0; i < wordList.size(); ++ i) {
				if (wordList[i].size() != endWord.size()) 
					continue;
				int diff = 0;
				for (int j = 0; j < endWord.size(); ++ j) {
					if (wordList[i].at(j) != transfer.first.at(j))
						diff ++;
					if (diff > 1)
						break;
				}
				if (diff == 1) {
					bfsqueue.push({wordList[i], transfer.second+1});
					wordList[i] = "";
				}
			}
		}

		return shortest == INT_MAX ? 0:shortest;
	}
};

/* brute-force DFS solution cannot pass OP */
class Solution {
public:
	int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
		int shortest = INT_MAX, nonExist = 1;
		backtarckhelper(beginWord, endWord, wordList, 1, shortest);
		return shortest == INT_MAX ? 0:shortest;
	}

	void backtarckhelper(string transfer, string& target, vector<string>& wordList,
		int curres, int& shortest) {
		if (transfer == target) {
			shortest = min(shortest, curres);
			return;
		}

		for (int i = 0; i < wordList.size(); ++ i) {
			int diff = 0;
			for (int j = 0; j < transfer.size(); ++ j) {
				if (wordList[i].at(j) != transfer[j])
					diff ++;
				if (diff > 1)
					break;
			}
			if (diff == 1) {
				string tem = wordList[i];
				wordList.erase(wordList.begin()+i);
				backtarckhelper (tem, target, wordList, curres+1, shortest);
				wordList.insert(wordList.begin()+i, tem);
			}
		}
	}

};

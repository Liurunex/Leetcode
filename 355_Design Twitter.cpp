class Twitter {
private:
	unordered_map<int, unordered_set<int>> users;
	unordered_map<int, vector<pair<int, int>>> tweets;
	int timecount;
public:
	/** Initialize your data structure here. */
	Twitter() {
		timecount = 0;
	}

	/** Compose a new tweet. */
	void postTweet(int userId, int tweetId) {
		if (!users[userId].count(userId))
			users[userId].insert(userId);
		tweets[userId].push_back({timecount++, tweetId});
	}

	/** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
	vector<int> getNewsFeed(int userId) {
		int counter = 0;
		vector<int> res;
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> mostrecent;
		
		for (auto it = users[userId].begin(); it != users[userId].end(); ++ it) {
			int counter = 0;
			for (auto utweet = tweets[*it].rbegin(); utweet != tweets[*it].rend(); ++ utweet) {
				if (counter >= 10 || mostrecent.size() >= 10 && mostrecent.top().first > (*utweet).first)
					break;
				mostrecent.push(*utweet);
				if (mostrecent.size() > 10)
					mostrecent.pop();
				counter ++;
			}
		}
		
		while (!mostrecent.empty()) {
			res.push_back(mostrecent.top().second);
			mostrecent.pop();
		}
        reverse(res.begin(), res.end());
		return res;
	}

	/** Follower follows a followee. If the operation is invalid, it should be a no-op. */
	void follow(int followerId, int followeeId) {
		if (followeeId == followerId) return;
		if (!users[followerId].count(followeeId))
			users[followerId].insert(followeeId);
	}

	/** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
	void unfollow(int followerId, int followeeId) {
		if (followeeId == followerId) return;
		if (users[followerId].count(followeeId))
			users[followerId].erase(followeeId);
	}
};

/* the idea: one timestamp, two hash map storing the followee of each user, and the tweets of each user respectively,
 * the only trick is to get the most 10 tweets of a user: what we do is iterate all followees of this
 * user inluding himself, then we maintain a priority_queue (min heap), go throgh all tweets of this
 * followee, NOTICE we need travel reversely since tweets was ordered by timestamp and we only need the
 * last 10 tweets for comparing; Once the priority_queue has more than 10 elements and its top (min value)
 * is bigger than current tweets timestamp, we should break this iteartion since the latter tweets cannot
 * excess anymore! NOTICE each time we push a new into our pq, we should check if we should do pop to
 * maintain the 10-size priority queue. One last thing, the pq store all tweets from earliest to most
 * recent time, so our result should be reversed so that more recent tweets go first
 **/

class Twitter {
private:
	unordered_map<int, unordered_set<int>> users;
	vector<pair<int, int>> tweets;
public:
	/** Initialize your data structure here. */
	Twitter() {
	}

	/** Compose a new tweet. */
	void postTweet(int userId, int tweetId) {
		if (!users[userId].count(userId))
			users[userId].insert(userId);
		tweets.push_back({tweetId, userId});
	}

	/** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
	vector<int> getNewsFeed(int userId) {
		int counter = 0;
		vector<int> res;
		for (auto i = tweets.rbegin(); i != tweets.rend(); ++ i) {
			if (counter >= 10) break;
			if (users[userId].count(i->second)) {
				counter ++;
				res.push_back(i->first);
			}
		}
		return res;
	}

	/** Follower follows a followee. If the operation is invalid, it should be a no-op. */
	void follow(int followerId, int followeeId) {
		if (followeeId == followerId) return;
		if (!users[followerId].count(followeeId))
			users[followerId].insert(followeeId);
	}

	/** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
	void unfollow(int followerId, int followeeId) {
		if (followeeId == followerId) return;
		if (users[followerId].count(followeeId))
			users[followerId].erase(followeeId);
	}
};
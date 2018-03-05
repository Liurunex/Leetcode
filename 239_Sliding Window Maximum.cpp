class Solution {
public:
	vector<int> maxSlidingWindow(vector<int>& nums, int k) {
		deque<int> dq;
		vector<int> res;

		for (int i = 0; i < nums.size(); ++ i) {
			// to make sure current window is [i-k+1, i]
            if (!dq.empty() && dq.back() == i-k)
                dq.pop_back();			

			while (!dq.empty() && nums[i] > nums[dq.front()])
                dq.pop_front();
			
            dq.push_front(i);
			
			if (i >= k-1)
				res.push_back(nums[dq.back()]);
		}
		return res;
	}
};

/* the idea: Monotonic thought. We maintain a deque which stores at most the k-window
 * size element in acsending order. The reason to use deque is due to the deque like
 * double-linked list provide O(1) opeartion on head and tail. By iterating all number,
 * we compare the current value with the deque.head(), which is the minimal value in
 * previous k-window, our job here is to find the first element in dequeu that is greater
 * or equal to current value, then we drop all those small values in dequeu, SINCE they 
 * can never be candiate of maxmium value of later k-window!! Then we push current value 
 * inside deque (it either be max or min!), we then push the head of deque into result once
 * the iterating index is larger than k-2, SINCE we start at empty dequeu! ONE MORE THING:
 * we should check at first if the current maximum value is out of k-size window [i-k+1, i],
 * if ourside, we should pop that head out, but this operation will be at most once, SINCE
 * we at most have k element inside dequeue
 */ 

class Solution {
public:
	vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if (!k || !nums.size()) return {};
		priority_queue<pair<int, int>> tem;
		vector<int> res;
		int left = 0, right = k-1;
        for (int i = 0; i < k; ++ i)
            tem.push({nums[i], i});
        res.push_back(tem.top().first);
        
		for (int i = k; i < nums.size(); ++ i) {
            left ++;
            right ++;
            tem.push({nums[i], i});
            while (tem.top().second < left || tem.top().second > right)
                tem.pop();
             res.push_back(tem.top().first);
		}
		return res;
	}
};

/* the idea: Min Heap + two pointer. We use a priority queue pq to maintain
 * a size k window. However, the pq cannot remove a element directly, we then
 * use two pointer to mark the left and right boundary of the window. Meanwhile,
 * our heap pq sotres both the value and index. Each time we need to remove a number
 * from window pq, we just check if top's index is located in [left, right], so that
 * we sometimes don't acutally remove that number but maintain it in heap.
 * */
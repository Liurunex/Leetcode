class MedianFinder {
struct cmp{
	bool operator() (int a, int b) {
		return a > b;
	}
};
private:
	priority_queue<int, vector<int>, cmp> minRight;
	priority_queue<int> maxLeft;
public:
	/** initialize your data structure here. */
	MedianFinder() {

	}

	void addNum(int num) {

		if (!minRight.size() || num > minRight.top()) {
			if (minRight.size() <= maxLeft.size())
				minRight.push(num);
			else {
				maxLeft.push(minRight.top());
				minRight.pop();
				minRight.push(num);
			}
		}
		else if (!maxLeft.size() || num < maxLeft.top()) {
			if (maxLeft.size() <= minRight.size())
				maxLeft.push(num);
			else {
				minRight.push(maxLeft.top());
				maxLeft.pop();
				maxLeft.push(num);
			}
		}
		else {
			if (minRight.size() >= maxLeft.size())
				maxLeft.push(num);
			else minRight.push(num);
		}
	}

	double findMedian() {
		if (!minRight.size() && !maxLeft.size())
			return 0;
		if (minRight.size() == maxLeft.size())
			return (double)(minRight.top()+maxLeft.top())/2;
		if (minRight.size() > maxLeft.size())
			return (double)minRight.top();
		else return (double)maxLeft.top();
	}
};
/* the idea: we use two heap to store the whole data, that is, a Max heap to store the integer from start to 
 * median in sorted order, while a Min heap to stores integers from median to end; what we want do here is 
 * untilize the feature of heap to make sure the root of MaxLeft heap and MinRight head are candiates of the
 * whole data struture, the the size differences between two heap will not greater than 1:
 * findMedian(), it runs O(1), if the MinRight has more nodes, then its root is the median, vice versa; if both
 * heap has same size, then the median will be the mean of two heaps; NOTICE the case where both heap is 0 size;
 * addNum(), it runs O(log(m)) where m is the depth of the heap which the number is going to be inserted; the process
 * is first judge if the number lay in the MinRight Heap, MaxLeft Heap or the interval of two Heap; if it lays in the
 * interval, we add the numebr into the heap who has less nodes; in other two cases they are same, let's show the case
 * where the number belong to the MaxLeft: we want to insert the number into the MaxLeft, we first judege the size 
 * difference between two Heaps, if the MaxLeft has less nodes, then we just simply add it to the MaxLeft and we are
 * donel; if MaxLeft has more nodes, then we cannot simly add number into MaxLeft, NOTICE SINCE WE MUST MAINTAIN THE
 * DIFFERENCE OF SIZE BETWEEN TWO HEAPS IS NO MORE THAN 1, under his concern, we have to push number into MaxLeft, since
 * the number is less than MaxLeft.top(), thus the root of MaxLeft is the maximum value of the heap, so that we will
 * add the MaxLeft Heap Root into MinRight, then pop the root of MaxLeft to make the two heap have 0 differnce on size
 * then we can add the number into MaxLeft
 * the trick: overload the comaprator of pq, the intial cases corner cases
 * /

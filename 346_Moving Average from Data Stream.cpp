class MovingAverage {
private:
	int windowsize;
	double sum;
	queue<int> thequeue;
public:
	/** Initialize your data structure here. */
	MovingAverage(int size): windowsize(size), sum(0) {
	}

	double next(int val) {
		if (thequeue.size() == windowsize) {
			sum -= thequeue.front();
			thequeue.pop();
		}
		sum += val;
		thequeue.push(val);
		return sum/thequeue.size();
	}
};

/* the idea: we use a constant size queue to store all
 * elements in the sliding window, and a double number sum
 * to record the sum of the window
 */

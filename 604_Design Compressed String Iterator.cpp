class StringIterator {
private:
	string str;
	size_t index;
	char cur;
	int counter;
public:
	StringIterator(string compressedString) {
		str     = compressedString;
		index   = 0;
		counter = 0;
	}

	char next() {
		if (hasNext()) {
			counter --;
			return cur;
		}
		return ' ';
	}

	bool hasNext() {
		if (counter) return true;
		if (index < str.size()) {
			cur = str.at(index ++);
			while (str[index] >= '0' && str[index] <= '9')
				counter = counter*10 + str[index ++] - '0';
			return true;
		}
		return false;
	}
};
/* the idea: basically we use hasNext to iterate to next char and assign
 * the value of curchar, then call next for return and decrease counter
 */
/**
 * Your StringIterator object will be instantiated and called as such:
 * StringIterator obj = new StringIterator(compressedString);
 * char param_1 = obj.next();
 * bool param_2 = obj.hasNext();
 */

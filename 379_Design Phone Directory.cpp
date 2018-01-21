class PhoneDirectory {
private:
    vector<int> status;
    vector<int> lst;
    int cap, next;
public:
    /** Initialize your data structure here
    @param maxNumbers - The maximum numbers that can be stored in the phone directory. */
    PhoneDirectory(int maxNumbers) {
        status.resize(maxNumbers, 1);
        lst.resize(maxNumbers);
        for (int i = 0; i < maxNumbers; ++ i)
            lst[i] = i;
        cap  = maxNumbers;
        next = 0;
        
    }

    /** Provide a number which is not assigned to anyone.
    @return - Return an available number. Return -1 if none is available. */
    int get() {
        if (next >= cap)
            return -1;
        int res = lst[next ++];
        status[res] = 0;
        return res;
    }

    /** Check if a number is available or not. */
    bool check(int number) {
        return status[number];
    }

    /** Recycle or release a number. */
    void release(int number) {
        if (!status[number]) {
            status[number] = 1;
            lst[--next] = number;
        }
    }
};

/* the idea: design + random thought. Two vectors, one to record status of each number, another
 * is the number list. The key part is release a number: we first set the status of that number
 * to 1, then we should return that number, we assign that number to lst[--next], why? since next
 * might have reach the end of lst, and we have assure that all number before next has been used, since
 * we just increase the next in get(), therefore we reassign that number to lst[--next]. In this way,
 * the list original order has totally be disturbed but the number is still here. */
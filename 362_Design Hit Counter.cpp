class HitCounter {  
    private:
        int window_size = 300;
        vector<int> hitstructure;
    public:
    /** Initialize your data structure here. */
    HitCounter() {

    }

    /** Record a hit.
        @param timestamp - The current timestamp (in seconds granularity). */
    void hit(int timestamp) {
        hitstructure.push_back(timestamp);
    }

    /** Return the number of hits in the past 5 minutes.
        @param timestamp - The current timestamp (in seconds granularity). */
    int getHits(int timestamp) {
        int pre_hits = slef_upper_bound(timestamp-300);
        //cout  << " pre " << pre_hits << endl;
        return hitstructure.size() - pre_hits;
    }

    int slef_upper_bound(int timestamp) {
        int left = 0, right = hitstructure.size()-1;
        while (left <= right) {
            int mid = left + (right-left)/2;
            if (hitstructure[mid] > timestamp)
                right = mid-1;
            else left = mid+1;
        }
        return left;
    }
};
/* the idea: vector + binary search upper bound: we use vector to store all timestamp when
 * hit happened, then we use upper_bound_search to find the first timestamp that is big 
 * than cur_timestamp-300, then we are done */
/* the BETTER IDEA: we use two vectors: timerecords record the real timestamp of a "realteive" timestamp in
 * the 5-minute window, eg: 301s == 1s so put at timerecords[1]; hitrecords recrod the hit counts corresponding
 * to the "relative" timestamps; the key thought: in hit(): we mode the timestamp by 300 to get its "relative"
 * position in timerecord, and then we check if the corresponding timestamp[index] == timestamp, if yes, that
 * mean multiple hits at this time, if not, we should reset it to 1 since we the previous real time at this
 * relative time position is expired from the 5-minute window!!!
 */

class HitCounter {  
    private:
        vector<int> timerecords; // the 5-minute window of time real time records
        vector<int> hitrecords; // the 5-minute window of hits corresponding to timerecords
    public:
    /** Initialize your data structure here. */
    HitCounter() {
        timerecords.resize(300);
        hitrecords.resize(300);
    }

    /** Record a hit.
        @param timestamp - The current timestamp (in seconds granularity). */
    void hit(int timestamp) {
        int index = timestamp % 300;
        if (timerecords[index] != timestamp) {
            timerecords[index] = timestamp;
            hitrecords[index] = 1;
        }
        else hitrecords[index] ++;

    }

    /** Return the number of hits in the past 5 minutes.
        @param timestamp - The current timestamp (in seconds granularity). */
    int getHits(int timestamp) {
        int res = 0;
        for (int i = 0; i < 300; ++ i) {
            if (timerecords[i] > timestamp - 300)
                res += hitrecords[i];
        }
        return res;
    }

};
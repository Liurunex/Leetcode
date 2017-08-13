class Vector2D {
private:
	vector<vector<int>>::iterator irow, iend;
	size_t jcol = 0;
public:
    Vector2D(vector<vector<int>>& vec2d) {
		irow = vec2d.begin();
		iend = vec2d.end();
    }

    int next() {
        return (*irow).at(jcol ++); 
	}

    bool hasNext() {
    	auto trow = irow;
		while (irow != iend && jcol == (*irow).size()) {
            irow ++;
            jcol = 0;
        }
		return irow != iend;
	}
};

/* you don't need consider the {} case especially, just let it be size() */
}



class Vector2D {
private:
	vector<vector<int>>::iterator irow, iend;
	vector<int>::iterator jcol;
public:
    Vector2D(vector<vector<int>>& vec2d) {
		
		irow = vec2d.begin();
		while ((*irow).size() == 0) {
			irow ++;
		}
		iend = vec2d.end();
		jcol = (*irow).begin();
    }

    int next() {
		int res = *jcol;
		auto trow = irow;
		while ((*trow).size() == 0)
			trow ++;
		jcol ++;
		if (trow != iend) {
			if (jcol == (*irow).end()) {
				jcol = (*trow).begin();
				irow = trow;
			}
		}
		return res;
	}

    bool hasNext() {
    	auto trow = irow;
		while ((*trow).size() == 0)
			trow ++;
		if (trow == iend && jcol == (*irow).end())
			return false;
		return true;
	}
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D i(vec2d);
 * while (i.hasNext()) cout << i.next();
 */


class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty() || matrix[0].empty()) 
            return false;
    	if(target < matrix[0][0]) return false; 
		vector<int> headers;
		int head = 0, tail = 0, mid = 0;
		for (int i = 0; i < matrix.size(); i++) 
			headers.push_back(matrix[i][0]);

		tail = headers.size()-1;
		while (head <= tail) {
			mid = head + (tail-head)/2;
			if (target > headers[mid]) 
			    head = mid + 1;
			if (target == headers[mid])
				return true;
			if (target < headers[mid])
				tail = mid-1;
		}
        
		int row = 0;
		if (target > matrix[mid][0])
		    row = mid;
	    else row = mid-1;
	    
		vector<int> rowers (matrix[row]);
		head = 0;
		tail = rowers.size()-1;
		while (head <= tail) {
			mid = head + (tail-head)/2;
			if (target > rowers[mid])
				head = mid + 1;
			if (target == rowers[mid])
				return true;
			if (target < rowers[mid])
				tail = mid-1;
			mid = head + (tail-head)/2;
		} 

		return false;
    }
};
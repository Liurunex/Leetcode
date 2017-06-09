class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        if (matrix.size() == 0) return {};
        int row = matrix.size(), col = matrix[0].size(), limit = min(row, col);
        vector<int> res;
        int i = 0, j = 0, dir = true, time = 0, num = row * col;
        while(time < num) {
        	cout << '[' << i <<']' << '['<< j << ']' << endl;
        	time ++;
        	res.push_back(matrix[i][j]);
        	if (dir) {
        		i --; j ++;
        		if (i < 0 && j >= col) {
        			i += 2; 
        			j --;
        			dir = false;
        		}
        		else if (i < 0) {
        			i ++; 
        			dir = false;
        		}
    			else if (j >= col) {
    				i += 2;
    				j --;
    				dir = false;
    			}

        	}
        	else {
        		i ++; j --;
        		if (i >= row && j < 0) {
        			i --;
        			j += 2;
        			dir = true;
        		}
    			else if (i >= row) {
    				i --;
    				j += 2;
    				dir = true;
    			}
				else if (j < 0) {
					j ++;
					dir = true;
				}
        	}
        }
        return res;
    }
};
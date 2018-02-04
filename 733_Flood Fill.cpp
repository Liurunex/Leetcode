class Solution {
public:
	vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
		if (sr < 0 || sr >= image.size() || sc < 0 || sc >= image[0].size())
			return image;
		vector<vector<int>> visited (vector<vector<int>> (image.size(), vector<int>(image[0].size(), 0)));
		dfshelp(image, sr, sc, newColor, image[sr][sc], visited);
		return image;
	}

	void dfshelp(vector<vector<int>>& image, int sr, int sc, int newColor, int target, vector<vector<int>>& visited) {
		if (sr < 0 || sr >= image.size() || sc < 0 || sc >= image[0].size() || image[sr][sc] != target || visited[sr][sc])
			return;
		image[sr][sc] = newColor;
		visited[sr][sc] = 1;
		dfshelp(image, sr+1, sc, newColor, target, visited);
		dfshelp(image, sr-1, sc, newColor, target, visited);
		dfshelp(image, sr, sc+1, newColor, target, visited);
		dfshelp(image, sr, sc-1, newColor, target, visited);
	}
};

/* the idea: DFS */
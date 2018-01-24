class NumMatrix {
private:
    struct Node {
        int sum;
        Node* children[4] = {NULL, NULL, NULL, NULL};
        pair<int, int> lefttop;
        pair<int, int> rightbootm;
        Node (pair<int, int> x, pair<int, int> y): sum(0), lefttop(x), rightbootm(y) {}
    };
    
    Node* build(vector<vector<int>>& matrix, pair<int, int> start, pair<int, int> end) {
        if (start.first > end.first || start.second > end.second)
            return NULL;
        Node* node = new Node(start, end);
        if (start == end) {
            node->sum = matrix[start.first][start.second];
            return node;
        }
        int mid_x = start.first + (end.first-start.first)/2;
        int mid_y = start.second + (end.second-start.second)/2;

        node->children[0] = build(matrix, start, {mid_x, mid_y});
        node->children[1] = build(matrix, {start.first, mid_y+1}, {mid_x, end.second});
        node->children[2] = build(matrix, {mid_x+1, start.second}, {end.first, mid_y});
        node->children[3] = build(matrix, {mid_x+1, mid_y+1}, end);

        for (int i = 0; i < 4; ++ i) {
            if (node->children[i])
                node->sum += node->children[i]->sum;
        }
        return node;   
    }

    void Modify(int& row, int& col, int& diff, Node* node) {
        if (!node || row < node->lefttop.first || row > node->rightbootm.first ||
            col < node->lefttop.second || col > node->rightbootm.second)
            return;
        node->sum += diff;
        // leaf node case
        if (node->lefttop == node->rightbootm)
            return;
        for (int i = 0; i < 4; ++ i) {
            if (node->children[i])
                Modify(row, col, diff, node->children[i]);
        }
    }

    int Query(int row1, int col1, int row2, int col2, Node* node) {
        if (!node || row1 > row2 || col1 > col2 ||
            node->lefttop.second > col2 || node->rightbootm.second < col1 ||
            node->lefttop.first > row2 || node->rightbootm.first < row1)
            return 0;
        if (node->lefttop == make_pair(row1, col1) && node->rightbootm == make_pair(row2, col2))
            return node->sum;
        auto start = node->lefttop;
        auto end   = node->rightbootm;

        int mid_x = start.first + (end.first-start.first)/2;
        int mid_y = start.second + (end.second-start.second)/2;

        int res = 0;
        
        res += Query(max(row1, start.first), max(col1, start.second), 
            min(row2, mid_x), min(col2, mid_y), node->children[0]);
        res += Query(max(row1, start.first), max(col1, mid_y+1), 
            min(row2, mid_x), min(col2, end.second), node->children[1]);
        res += Query(max(row1, mid_x+1), max(col1, start.second), 
            min(row2, end.first), min(col2, mid_y), node->children[2]);
        res += Query(max(row1, mid_x+1), max(col1, mid_y+1), 
            min(row2, end.first), min(col2, end.second), node->children[3]);

        return res;
    }

    Node* root;
    vector<vector<int>> dup;

public:
    NumMatrix(vector<vector<int>> matrix) {
        if (!matrix.size() || !matrix[0].size())
            return;
        dup = matrix;
        root = build(matrix, {0,0}, {matrix.size()-1, matrix[0].size()-1});
    }
    
    void update(int row, int col, int val) {
        int diff = val - dup[row][col];
        if (diff) {
            dup[row][col] = val;
            Modify(row, col, diff, root);
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return Query(row1, col1, row2, col2, root);
    }
};

/* the idea: Segement Tree -> Quad Tree. Basically it's same as segement tree except rasing to
 * 2-dimension matrix. The difference is we divide each node into 4 sub-nodes just like a coordinate:
 * we denote them as left-top and right-bottom points, for a node with start and end pointer:
 * we diveide it into: 
 *      node->children[0] = start, {mid_x, mid_y})
 *      node->children[1] = {start.first, mid_y+1}, {mid_x, end.second})
 *      node->children[2] = {mid_x+1, start.second}, {end.first, mid_y})
 *      node->children[3] = {mid_x+1, mid_y+1}, end)
 * the other function is exactly like segement tree implement, NOTICE the query fucntion using min and max
 * function to locate the area count into result.
 * NOTICE: using array instead of vector to avoid TLE
 */
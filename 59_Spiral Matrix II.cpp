// Example program
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    int n = 3;
    /*vector<vector<int>> matrix;
    int i,j = 0;
    for (i = 0; i < n; i++) {
        vector<int> tem;
        for (j = 0; j < n; j++)
            tem.push_back(0);
        matrix.push_back(tem);
    }*/
    vector<vector<int>> matrix(n,vector<int>(n,0));
    
    int rounds = n/2;
    int left = 0, top = 0;
    int right = n-1, bottom = n-1;
    int insert = 1;
    
    while (rounds > 0) {
        for (i = top, j = left; j <= right; j++) 
            matrix[i][j] = insert ++;
        cout << right << endl;
        for (i = top+1, j = right; i <= bottom; i++)
            matrix[i][j] = insert ++;
        for (i = bottom, j = right-1; j >= left; j--)
            matrix[i][j] = insert ++;
        for (i = bottom-1, j = left; i > top; i--)
            matrix[i][j] = insert ++;
        left ++;
        top ++;
        right --;
        bottom --;
        rounds --;
    }
    
    if (n%2 == 1)
        matrix[n/2][n/2] = n*n;
   
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++)
            cout << matrix[i][j] << " ";
        cout << endl;
    }
}

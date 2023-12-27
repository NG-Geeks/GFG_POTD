Question ::Anti Diagonal Traversal of Matrix

Give a N*N square matrix, return an array of its anti-diagonals in top-leftmost to bottom-rightmost order. In an element of a anti-diagonal (i, j), surrounding elements will be (i+1, j-1) and (i-1, j+1). Look at the examples for more clarity.

Solution::

Complexity
Time complexity:
    O(N*M)
Space complexity:
    O(N*M)
Code
#pragma gcc optimize("03")
auto init = [] (){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();
class Solution {
  public:
    vector<int> antiDiagonalPattern(vector<vector<int>> matrix) 
    {
        int n = matrix.size();
        vector<int> ans;
        
        // first part
        for(int j = 0; j < n; j++){
            for(int x = 0, y = j; y > -1 and x < n; x++, y--){
                ans.push_back(matrix[x][y]);
            }
        }
        
        // second part
        for(int i = 1; i < n; i++){
            for(int y = n - 1, x = i; y > -1 and x < n; x++, y--){
                ans.push_back(matrix[x][y]);
            }
        }
        
        return ans;
    }
};

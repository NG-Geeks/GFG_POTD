Question ::Largest rectangular sub-matrix whose sum is 0

Given a matrix mat[][] of size N x M. The task is to find the largest rectangular sub-matrix by area whose sum is 0.

If there are multiple solutions return the rectangle which starts from minimum column index. If you still have multiple solutions return the one starting from minimum row index. If you still have multiple solutions return the one having greatest row number. If no such matrix is present return a zero (0) size matrix.
Solution::

class Solution{
  public:
  vector<vector<int>> sumZeroMatrix(vector<vector<int>> a){
      int n = a.size() , m = a[0].size();
      vector<vector<int>>prefix(n+1,vector<int>(m+1,0));
      for(int i =1 ; i<n+1;i++){
          for(int j =1 ; j< m+1; j++){
              prefix[i][j] = prefix[i][j-1] + a[i-1][j-1];
          }
      }
      int best = 0 ;
      int sx , sy , ex , ey;
      for(int i=1  ; i<n+1 ; i++){
          for(int j = i; j<m+1 ;j++){
              unordered_map<int,int>m;
              m[0] = 0;
              int sum =0;
              for(int k = 1 ; k<n+1 ; k++){
                  sum +=prefix[k][j]  - prefix[k][i-1];
                  if(m.count(sum)){
                      int area =( j-i+1) * (k - m[sum]);
                      if(area > best){
                          best  = area;
                          sx = m[sum] + 1;
                          sy = i;
                          ex = k ;
                          ey = j;
                      }
                  }
                  else{
                      m[sum ] = k;
                  }
              }
              
          }
      }
      vector<vector<int>>ans;
      if(best == 0 )return ans;
      
      for(int i = sx;i<=ex;i++){
          vector<int>curRow;
          for(int j = sy ; j<=ey;j++){
              curRow.push_back(a[i-1][j-1]);
          }
          ans.emplace_back(curRow);
      }
      return ans;
  }
};


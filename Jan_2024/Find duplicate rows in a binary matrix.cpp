Question :: Find duplicate rows in a binary matrix
MediumAccuracy: 60.19%Submissions: 15K+Points: 4

Given a boolean matrix of size RxC where each cell contains either 0 or 1, find the row numbers (0-based) of row which already exists or are repeated.

Solution::

Complexity
Time complexity:
    O(R*C)
Space complexity:
    O(1)


Code::
class Solution
{   
    public:
    vector<int> repeatedRows(vector<vector<int>> &m, int M, int N) 
    {     
          vector<int>v;
          for(int i = 0 ; i<M ; i++){
              if(i!=0)
              if(find(m.begin(),m.begin()+i,m[i]) != m.begin()+i){
                  v.push_back(i);
              }
              
          }
          return v;
    } 
};
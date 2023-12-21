Candy

There are N children standing in a line. Each child is assigned a rating value given in the integer array ratings.
You are giving candies to these children subjected to the following requirements:

Each child must have atleast one candy.
Children with a higher rating than it's neighbours get more candies than neighbors.
Return the minimum number of candies you need to have to distribute.

Solution::
class Solution {
  public:
    int minCandy(int N, vector<int> &ratings) {
      vector<int>v(N,1);
      for(int i=1;i<N;i++){
          if(ratings[i]>ratings[i-1])
          v[i] = max(v[i] , v[i-1]+1);
      }
      
      for(int i = N-2;i>=-1;i--){
          if(ratings[i] > ratings[i+1])
           v[i] = max(v[i] , v[i+1]+1);
      }
      return accumulate(begin(v) , end(v) , 0LL);
    }
};
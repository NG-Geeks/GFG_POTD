Shortest Common Supersequence
Given two strings X and Y of lengths m and n respectively, find the length of the smallest string which has both, X and Y as its sub-sequences.
Note: X and Y can have both uppercase and lowercase letters.

Solution::
class Solution
{    int solve(string a, string b,int i,int j,vector<vector<int>>&dp){
    if(i==a.length())
      return 0;
    if(j==b.length())
      return 0;

if(dp[i][j]!=-1)return dp[i][j];
    int ans =0;
    if(a[i]==b[j])
        ans = 1+solve(a,b,i+1,j+1,dp);
    else{
        ans = max(solve(a,b,i+1,j,dp),solve(a,b,i,j+1,dp));
    }      
   return dp[i][j]=ans;

}

    public:
    //Function to find length of shortest common supersequence of two strings.
    int shortestCommonSupersequence(string a, string b, int m, int n)
    {
      vector<vector<int>>dp(a.length(),vector<int>(b.length(),-1));
      return  a.length()+b.length() -  solve(a,b,0,0,dp);
    }
};  
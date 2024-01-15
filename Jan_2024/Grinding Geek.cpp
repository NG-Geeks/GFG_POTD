Question :: Grinding Geek
GeeksforGeeks has introduced a special offer where you can enroll in any course, and if you manage to complete 90% of the course within 90 days, you will receive a refund of 90%.

Geek was fascinated by this offer. This offer was valid for only n days, and each day a new course was available for purchase. Geek decided that if he bought a course on some day, he will complete that course on the same day itself and redeem floor[90% of cost of the course] amount back. Find the maximum number of courses that Geek can complete in those n days if he had total amount initially.
Note: On any day, Geek can only buy the new course that was made available for purchase that day.
Solution::

Complexity
Time complexity:
    O(N)
Space complexity:
    O(N^2)


Code::
class Solution{
    int solve(int n , int total , vector<int>&cost , int i , vector<vector<int>>&dp){
        if(i>=n)return 0;
        if(dp[i][total]!=-1)return dp[i][total];
        int take =0;
        if(cost[i]<=total)
            take = 1 + solve(n , floor(total - (cost[i]*(0.1))) , cost , i+1 , dp);
        int notake = 0 + solve(n , total , cost , i+1 , dp);
        return dp[i][total] = max(take , notake);
    }
    public:
    int max_courses(int n, int total, vector<int> &cost)
    {    
        vector<vector<int>>dp(cost.size()+1 , vector<int>(total+1 , -1));
        return solve(n , total , cost , 0 , dp);
    }
};
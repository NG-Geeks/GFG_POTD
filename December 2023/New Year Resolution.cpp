Question :: New Year Resolution

As the clock struck midnight on New Year's Eve, Geek bid farewell to the wasted moments of 2023, realizing the untapped potential of GFG's Problem of the Day.

His 2024 resolution: Solve POTD every day.

Eager to earn coins for GFG Merchandise, Geek faces new rules:

Earning Coin: Geek can accumulate coins[i] by solving the POTD on the ith day, where 1 <= coins[i] <= 2024 and the sum of coins <= 2024.
Merchandise Eligibility: To purchase merchandise, the coins earned must be divisible by 20 or 24, or precisely equal to 2024.
Geek's resolutions often fades over time. Realistically, he can only commit to active participation for N (where N ≤ 366) days. Given the value of N and number of coins associated with each POTD, can Geek strategically solve some (or all) POTDs to become eligible for redeeming merchandise?


Solution::

Complexity
Time complexity:
    O(N * sum of coins)
Space complexity:
    O(N * Sum of coins)
Code
#pragma gcc optimize("03")
auto init = [] (){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

class Solution {
     bool solve(int coin[] , int n , int i , int sum , vector<vector<int>>&dp){
         if(i>=n){
             if( (sum>=24 && sum%24==0) or (sum>=20 && sum%20==0 ))return 1;
             else if (sum==2024)return sum;
             else return 0;
         } 
         if(dp[i][sum]!=-1)return dp[i][sum];
         
         return dp[i][sum] =  solve(coin , n ,i+1 , sum , dp ) or solve(coin , n ,i+1 , sum+coin[i] , dp);
     }

    public:
    int isPossible(int N , int coins[]) 
    {   
        vector<vector<int>>dp(N  , vector<int>(2025 , -1));
        return solve(coins , N, 0 ,0 , dp);
       
    }
    
};

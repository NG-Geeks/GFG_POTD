Question :: Count possible ways to construct buildings
MediumAccuracy: 38.53%Submissions: 47K+Points: 4

There is a road passing through a city with N plots on both sides of the road. Plots are arranged in a straight line on either side of the road. Determine the total number of ways to construct buildings in these plots, ensuring that no two buildings are adjacent to each other. Specifically, buildings on opposite sides of the road cannot be adjacent.

Using * to represent a plot and || for the road, the arrangement for N = 3 can be visualized as follows: * * * || * * *.

Note: As the answer can be very large, print it mod 109+7.
Solution::

Complexity
Time complexity:
    O(N )
Space complexity:
    O(1 )
Code
#pragma gcc optimize("03")
auto init = [](){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();
class Solution{
    const int mod = 1e9+7;
    int solve(int n , int i , int j  ,  vector<vector<long long>>&dp){
        if(i==n)return 1;
        
        if(dp[i][j]!=-1)return dp[i][j];
        if(j==0){
            int take = (solve(n , i+1 , 1 ,dp))%mod;
            int notake = (solve(n ,i+1 , 0 , dp))%mod;
            dp[i][j] = (take%mod+notake%mod)%mod;
        }
        else{
            dp[i][j] = (solve(n,i+1,0,dp))%mod;
        }
        return (dp[i][j])%mod;
    }
    int solveMem(int n ){
        vector<vector<int>>dp(n+1 , vector<int>(2,1));
        for(int i = n-1 ; i>=0 ; i--){
            for(int j = 1 ; j>=0 ; j--){
                    if(j==0){
                    int take = dp[ i+1] [1]%mod;
                    int notake = dp[i+1 ][ 0]%mod;
                        dp[i][j] = (take%mod+notake%mod)%mod;
                    }
                    else{
                        dp[i][j] =dp[i+1][0]%mod;
                    }
            }
        }
        return dp[0][0];
    }
    int solveSp(int n ){
        vector<int>curr(n+1,1);
        vector<int>next(n+1,1);
        for(int i = n-1 ; i>=0 ; i--){
            for(int j = 1 ; j>=0 ; j--){
                    if(j==0){
                    int take = next [1]%mod;
                    int notake = next[ 0]%mod;
                       curr[j] = (take%mod+notake%mod)%mod;
                    }
                    else{
                        curr[j] =next[0]%mod;
                    }
            }
            next = curr;
        }
        return curr[0];
    }
	public:
	int TotalWays(int N)
	{  
	   // vector<vector<long long>>dp(N+1 ,vector<long long>(2,-1));
	   // long long k =  solve(N , 0,0 , dp);
	   // long long k = solveSp(N);
	    long long k = solveMem(N);
	    return (k*k)%mod;
	}
};
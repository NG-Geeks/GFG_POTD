Question :: Largest Sum Subarray of Size at least K

Given an array a of length n and a number k, find the largest sum of the subarray containing at least k numbers. It is guaranteed that the size of array is at-least k.

Solution::

Complexity
Time complexity:
    O(N )
Space complexity:
    O(N )
Code
#pragma gcc optimize("03")
auto init = [](){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();
class Solution{
    public:    
    long long int maxSumWithK(long long int a[], long long int n, long long int k) 
    {
        long long sum =0;
        long long maxi = INT_MIN;
        vector<long long>dp(n+1);
        for(int i=n-1;i>=0;i--){
            dp[i] = dp[i+1] + a[i];
            dp[i] = max(0LL ,dp[i] );
        }
        
        for(int i=0;i<k;i++){
            sum+=a[i];
        }
        for(int i=k;i<n;i++){
            long long res = sum + dp[i];
            maxi = max(res , maxi);
            
            sum+=a[i];
            sum-=a[i-k];
        }
        return max(maxi , sum);
    }
};
Maximum sum increasing subsequence
LINK->https://practice.geeksforgeeks.org/problems/maximum-sum-increasing-subsequence4749/1
 Given an array of n positive integers.Find the sum of the maximum sum subsequence of the given array such that the integers in the subsequence are sorted in strictly increasing order i.e.a strictly increasing subsequence.Solution::

class Solution
{

public:
	int maxSumIS(int arr[], int n)
	{
		int ans = INT_MIN;
		vector<int> dp(n);
		for (int i = 0; i < n; i++)
		{
			int maxi = INT_MIN;
			for (int j = 0; j < i; j++)
			{
				if (arr[j] < arr[i])
				{
					if (maxi == INT_MIN)
						maxi = dp[j];
					else if (dp[j] > maxi)
					{
						maxi = dp[j];
					}
				}
			}
			if (maxi == INT_MIN)
			{
				dp[i] = arr[i];
			}
			else
				dp[i] = maxi + arr[i];

			if (dp[i] > ans)
				ans = dp[i];
		}
		return ans;
	}
};
Question :: Longest subarray with sum divisible by K

Given an array arr containing N integers and a positive integer K, find the length of the longest sub array with sum of the elements divisible by the given value K.
Solution::

Complexity
Time complexity:
    O(N ).
Space complexity:
    O(N)


Code::


class Solution{
public:	
	int longSubarrWthSumDivByK(int arr[], int n, int k){  
	    int res = 0 , sum=0;
        unordered_map<int,int>m;
        m[0] = -1;
        for(int i=0 ; i<n;i++){
            sum += arr[i];
            int r = sum%k;
            if(r<0)r += k;
            if(m.count(r)){
                int ans = i - m[r];
                res = max(ans , res);
            }
            else m[r] = i;
        }
        return res;
	}
};
Question :: Split Array Largest Sum
 
Given an array arr[] of N elements and a number K., split the given array into K subarrays such that the maximum subarray sum achievable out of K subarrays formed is minimum possible. Find that possible subarray sum.

Solution::

Complexity
Time complexity:
    O(N*log(sum(arr))).
Space complexity:
    O(1 )


Code::
class Solution {
    int no_of_subarray_possible_with_mid(int  nums[] , int mid, int n ){
        int cnt = 1 ;
        int sum =0;

        for(int  i=0  ; i<n ; i++){
            if(sum + nums[i]>mid){
                sum = nums[i];
                cnt++;
            }
            else sum+=nums[i];
        }
        return cnt;
    }
public:
    int splitArray(int nums[] ,int N, int k) {
        int s = *max_element(nums , nums+N );
        int e = accumulate(nums , nums+N , 0);
        int ans = s;
        while(s<=e){
            int mid = (s+e)/2;
            int n = no_of_subarray_possible_with_mid(nums , mid, N);
            if(n>k) s = mid +1;
            else{
                ans = mid;
                e = mid-1;
            }
        }
        return ans;
    }
};
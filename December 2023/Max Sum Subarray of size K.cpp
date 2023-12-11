Max Sum Subarray of size K
Given an array of integers Arr of size N and a number K. Return the maximum sum of a subarray of size K.

NOTE*: A subarray is a contiguous part of any given array.

Time Complexity::
    O(N)

Space Complexity::
    O(1)
   

Solution::
class Solution{   
public:
    long maximumSumSubarray(int K, vector<int> &arr , int N){
         long sum=0;
        int i;
        for( i=0;i<K;i++){
            sum += arr[i];
        }
        int j=0 ;
        i= K;
        long maxi =sum;
        while(i<N){
            sum-=arr[j];
            sum+=arr[i];
            maxi = max(maxi , sum);
            i++;
            j++;
        }
        return maxi;
    }
};
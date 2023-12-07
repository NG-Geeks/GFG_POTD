Number of subarrays with maximum values in given range

Given an array of N elements and L and R, print the number of sub-arrays such that the value of the maximum array element in that subarray is at least L and at most R.
Solution:: 
class Solution{
    public:
    long countSubarrays(int a[], int n, int l, int r)
    {  long empire =0;
        int start =0;
        long ans =0;
       for(int end =0 ;end<n;end++){
           if(a[end]>=l && a[end]<=r){
               empire = end -start +1;
           }
           else if(a[end]>r){
               empire =0;
               start = end+1;
           }
           ans += empire;
       }
        return ans;   
    }
};
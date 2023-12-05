Minimize the Heights II

Given an array arr[] denoting heights of N towers and a positive integer K.

For each tower, you must perform exactly one of the following operations exactly once.

Increase the height of the tower by K
Decrease the height of the tower by K
Find out the minimum possible difference between the height of the shortest and tallest towers after you have modified each tower.

You can find a slight modification of the problem here.
Note: It is compulsory to increase or decrease the height by K for each tower. After the operation, the resultant array should not contain any negative integers.

class Solution {
  public:
    int getMinDiff(int arr[], int n, int k) {
        sort(arr , arr+n);
        int mini = arr[n-1] - arr[0];
      
        for(int i=1;i<n;i++){
           if (arr[i]<k)continue;
           int minii = min(arr[0] + k , arr[i]-k);
           int maxii = max(arr[n-1]-k , arr[i-1]+k);
           mini = min(mini , maxii  - minii);
        }
       
        return mini;
    }
};
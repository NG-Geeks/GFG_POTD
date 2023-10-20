Form a number divisible by 3 using array digits
LINK-> https://practice.geeksforgeeks.org/problems/form-a-number-divisible-by-3-using-array-digits0717/1

You will be given an array arr of integers of length N. You can construct an integer from two integers by treating the integers as strings, and then concatenating them. For example, 19 and 4 can be used to construct 194 and 419.
The task is to find whether it’s possible to construct an integer using all the digits of these numbers such that it would be divisible by 3.
If it is possible then print 1 and if not print 0.

Solution:: 

class Solution {
  public:
    int isPossible(int n, int arr[]) {
        int sum=0;
        for(int i=0;i<n;i++){
            int k=arr[i];
            while(k){
                sum+=k%10;
                k/=10;
            }
        }
        if(sum%3==0)return 1;
        return 0;
    }
};
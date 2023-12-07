Transform to prime
Given an array of n integers. Find the minimum positive number to be inserted in array, so that sum of all elements of array becomes prime.

Time Complexity::
  O(N) + O(N) * O(sqrt(N))

Space Complexity::
   O(1)
   

Solution::
class Solution
{   bool isPrime(int n){
    if (n <= 1)return false;
    
    for (int i = 2; i <= sqrt(n); i++)
        if (n % i == 0)return false;
 
    return true;
}
    public:
    int minNumber(int arr[],int N)
    {
        int total=0;
        for(int  i=0;i<N;i++){
            total += arr[i];
        }
        int ans =0;
        for(int i=total ; i<100000000;i++){
            if(isPrime(i))return ans;
            else ans++;
        }
        return total;
    } 
};
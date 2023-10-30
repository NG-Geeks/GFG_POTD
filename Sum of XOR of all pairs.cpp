Sum of XOR of all pairs

Problem ::
Given an array of N integers, find the sum of xor of all pairs of numbers in the array arr. In other words, select all possible pairs of i and j from 0 to N-1 (i<j) and determine sum of all (arri xor arrj).

Solution::
class Solution{
    public:
    // Returns sum of bitwise OR
    // of all pairs
    long long int sumXOR(int arr[], int n)
    {
          long long int sum=0;
          for(int i=0;i<32;i++){
              int oc =0 , zc =0;
              for(int j =0 ;j<n;j++){
                  if(arr[j]&1)oc++;
                  else zc++;
                  arr[j]/=2;
              }
              sum+=oc* 1LL* zc * (1<<i);
          }
    	return sum;
    }
};
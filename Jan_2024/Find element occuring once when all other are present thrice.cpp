Question :: Find element occuring once when all other are present thrice

Given an array of integers arr[] of length N, every element appears thrice except for one which occurs once.
Find that element which occurs once.

Solution::

Complexity
Time complexity:
    O(N )
Space complexity:
    O(1 )
Code
#pragma gcc optimize("03")
auto init = [](){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();
class Solution {
  public:
    int singleElement(int arr[] ,int N) {
        int  xy=0;
        vector<int>array(32);
       for(int i=0 ; i <N;i++){
           for(int j=0  ; j<32 ; j++){
               array[j]+= (arr[i]>>j) & 1;
           }
       }
       for(int i=0 ; i <32 ; i++){
           xy += (array[i]%3)<<i;
       }
       return xy;
    }
};
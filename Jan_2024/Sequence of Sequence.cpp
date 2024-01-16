Question :: Sequence of Sequence
MediumAccuracy: 61.45%Submissions: 15K+Points: 4

Given two integers m and n, try making a special sequence of numbers seq of length n such that

seqi+1 >= 2*seqi 
seqi > 0
seqi <= m
Your task is to determine total number of such special sequences possible.
Solution::

Complexity
Time complexity:
    O(N*M)
Space complexity:
    O(N), Stack memory of recursion
CODE::
class Solution{
    int solve(int i , int m , int n){
        if(n==0){
            if(i<=m)return 1;
            return 0;
        }
        int ans = 0;
        for(int ind = i*2 ; ind<=m ; ind++){
            ans += solve(ind , m , n-1);
        }
        return ans;
    }
public:
    int numberSequence(int m, int n){
        int ans =0; 
       for(int i= 1 ; i<=m ; i++){
           ans += solve(i , m ,n-1);
       }
       return ans;
    }
};